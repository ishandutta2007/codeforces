#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int LEN,bit[65536];
struct BIT{
	uint a[3130];
	void set(int x){
		a[x>>5]|=1u<<(x&31);
	}
	void reset(int x){
		a[x>>5]|=(~0)^(1u<<(x&31));
	}
	bool get(int x){
		return (a[x>>5]>>(x&31))&1;
	}
	void operator |=(const BIT &b){
		for (int i=0;i<=LEN;i+=4){
			a[i]|=b.a[i];
			a[i+1]|=b.a[i+1];
			a[i+2]|=b.a[i+2];
			a[i+3]|=b.a[i+3];
		}
	}
	void clear(){
		for (int i=0;i<=LEN;i+=4)
			a[i]=a[i+1]=a[i+2]=a[i+3]=0;
	}
	int count(){
		int ans=0;
		for (int i=0;i<=LEN;i+=4){
			ans+=bit[a[i]&65535]+bit[a[i]>>16];
			ans+=bit[a[i+1]&65535]+bit[a[i+1]>>16];
			ans+=bit[a[i+2]&65535]+bit[a[i+2]>>16];
			ans+=bit[a[i+3]&65535]+bit[a[i+3]>>16];
		}
		return ans;
	}
	int find(){
		int ans=0;
		for (int i=0;i<=LEN&&!ans;i+=4){
			if (a[i+3]^(~0)) ans=i+3;
			if (a[i+2]^(~0)) ans=i+2;
			if (a[i+1]^(~0)) ans=i+1;
			if (a[i]^(~0)) ans=i;
		}
		For(i,0,31)
			if (!(a[ans]&(1u<<i)))
				return (ans<<5)+i;
		assert(0);
		return -1;
	}
}B[1005],ban,tmp;
const int V=10000005;
const int N=100005;
int mn[V],id[V];
int ans1[N],ans2[N];
int n,k,cnt,a[N],ID[V/10];
vector<int> vec[V/10];
void init(){
	For(i,0,65535) bit[i]=bit[i>>1]+(i&1);
	For(i,2,V-1) if (!mn[i]){
		id[i]=++*id;
		For(j,1,(V-1)/i)
			if (!mn[i*j]) mn[i*j]=i;
	}
}
void getBIT(int x){
	tmp.clear();
	for (;x!=1;){
		int v=mn[x];
		for (;x%v==0;x/=v);
		if (ID[v=id[v]])
			tmp|=B[ID[v]];
		else{
			For(i,0,vec[v].size()-1)
				tmp.set(vec[v][i]);
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	LEN=(n-1)>>5;
	For(i,0,n-1) scanf("%d",&a[i]);
	For(i,0,n-1){
		int x=a[i];
		for (;x!=1;){
			int v=mn[x];
			for (;x%v==0;x/=v);
			vec[id[v]].PB(i);
		}
	}
	For(i,1,*id)
		if (vec[i].size()>=1000){
			ID[i]=++cnt;
			For(j,0,vec[i].size()-1)
				B[cnt].set(vec[i][j]);
		}
	int s1=0,s2=0;
	if (k%2==1){
		For(i,0,n-1){
			getBIT(a[i]);
			tmp.set(i);
			if (tmp.count()<=n-2){
				int p1=tmp.find();
				tmp.set(p1);
				int p2=tmp.find();
				ban.set(p1); ans2[++s2]=p1;
				ban.set(p2); ans2[++s2]=p2;
				ban.set(i); ans2[++s2]=i;
				break;
			}
		}
	}
	int pos=0;
	if ((s2^k^1)&1){
		for (;s2<k&&s1<k;){
			for (;ban.get(pos);++pos);
			getBIT(a[pos]);
			tmp|=ban; tmp.set(pos);
			if (tmp.count()==n){
				ans1[++s1]=pos;
				ban.set(pos);
			}
			else{
				int p1=tmp.find();
				ban.set(p1); ans2[++s2]=p1;
				ban.set(pos); ans2[++s2]=pos;
			}
		}
	}
	else{
		for (;s2<k;){
			for (;ban.get(pos);++pos);
			getBIT(a[pos]);
			tmp|=ban; tmp.set(pos);
			ans2[++s2]=pos;
			if (tmp.count()==n)
				ban.set(pos);
			else{
				int p1=tmp.find();
				ban.set(p1);
				ban.set(pos);
			}
		}
	}
	if (s1>=k)
		For(i,1,k) printf("%d ",ans1[i]+1);
	else For(i,1,k) printf("%d ",ans2[i]+1);
}
/*
O(2

O(2^8)
O(log*2^8) 
*/