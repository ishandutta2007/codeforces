#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define y1 wzpakking
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int cnt[65536];
const int N=2005;
struct Bitset{
	uint a[65];
	Bitset(){
		memset(a,0,sizeof(a));
	}
	void set(int x){
		a[x>>5]|=1u<<(x&31);
	}
	Bitset operator |(const Bitset &b)const{
		Bitset ans;
		for (int i=0;i<64;i+=4){
			ans.a[i]=a[i]|b.a[i];
			ans.a[i+1]=a[i+1]|b.a[i+1];
			ans.a[i+2]=a[i+2]|b.a[i+2];
			ans.a[i+3]=a[i+3]|b.a[i+3];
		}
		return ans;
	}
	Bitset operator ^(const Bitset &b)const{
		Bitset ans;
		for (int i=0;i<64;i+=4){
			ans.a[i]=a[i]^b.a[i];
			ans.a[i+1]=a[i+1]^b.a[i+1];
			ans.a[i+2]=a[i+2]^b.a[i+2];
			ans.a[i+3]=a[i+3]^b.a[i+3];
		}
		return ans;
	}
	bool operator !=(const Bitset &b)const{
		Bitset ans;
		for (int i=0;i<64;i+=2)
			if (a[i]!=b.a[i]||a[i+1]!=b.a[i+1])
				return 1;
		return 0;
	}
	int findfi(){
		For(i,0,63) if (a[i])
			For(j,0,31) if (a[i]&(1u<<j))
				return (i<<5)|j;
		assert(0); 
	}
	int count(){
		int ans=0;
		for (int i=0;i<64;i+=4){
			ans+=cnt[a[i]&65535]+cnt[a[i]>>16];
			ans+=cnt[a[i+1]&65535]+cnt[a[i+1]>>16];
			ans+=cnt[a[i+2]&65535]+cnt[a[i+2]>>16];
			ans+=cnt[a[i+3]&65535]+cnt[a[i+3]>>16];
		}
		return ans;
	}
}b[N],a[N];
int n,m,Q,nxt[N];
set<pii> S;
set<int> ans;
void insert(int x,int y){
	//printf("insert %d %d\n",x,y);
	nxt[x]=y;
	if ((a[x]|a[y])!=a[y])
		ans.insert(x);
}
void erase(int x,int y){
	//printf("erase %d %d\n",x,y);
	if ((a[x]|a[y])!=a[y])
		ans.erase(x);
}
void insert(int x){
	pii tmp(a[x].count(),x);
	set<pii>::iterator pre,nxt;
	pre=nxt=S.lower_bound(tmp);
	if (nxt!=S.begin()){
		pre--;
		if (nxt!=S.end()){
			erase(pre->se,nxt->se);
			insert(x,nxt->se);
		}
		insert(pre->se,x);
	}
	else if (nxt!=S.end())
		insert(x,nxt->se);
	S.insert(tmp);
}
void erase(int x){
	pii tmp(a[x].count(),x);
	S.erase(tmp);
	set<pii>::iterator pre,nxt;
	pre=nxt=S.lower_bound(tmp);
	if (nxt!=S.begin()){
		pre--;
		erase(pre->se,x);
		if (nxt!=S.end()){
			insert(pre->se,nxt->se);
			erase(x,nxt->se);
		}
	}
	else if (nxt!=S.end())
		erase(x,nxt->se);
}
int main(){
	For(i,1,65535) cnt[i]=cnt[i/2]+(i&1);
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,m){
		b[i]=b[i-1];
		b[i].set(i);
	}
	For(i,1,n)
		insert(i);
	while (Q--){
		int x,l,r;
		scanf("%d%d%d",&x,&l,&r);
		erase(x);
		a[x]=a[x]^b[l-1]^b[r];
		insert(x);
		if (ans.empty()) puts("-1");
		else{
			int x=*ans.begin(),y=nxt[x];
			Bitset tmp=a[x]|a[y];
			int p=(a[x]^tmp).findfi();
			int q=(a[y]^tmp).findfi();
			if (x>y) swap(x,y);
			if (p>q) swap(p,q);
			printf("%d %d %d %d\n",x,p,y,q);
		}
	}
}