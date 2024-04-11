#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
const int pri[]={0,2,3,5,7,11,13,17,19,23,29,31,37};
int n,m,L[N],a[N];
vector<pii> vec[N];
struct node{
	int fl;
	int a[15];
	int b[15];
	node(){
		fl=1;
		For(i,1,12) a[i]=1;
		For(i,1,12) b[i]=0;
	}
	void insert(int x,int y){
		For(i,1,12){
			for (;x%pri[i]==0;)
				x/=pri[i],a[i]*=pri[i];
			//if (a[i]!=1) cout<<a[i]<<' '<<y%a[i]<<endl;
			b[i]=y%a[i];
		}
	}
	node operator +(const node &tmp)const{
		node ans;
		ans.fl=fl&tmp.fl;
		For(i,1,12)
			if (a[i]>=tmp.a[i]){
				if (b[i]%tmp.a[i]!=tmp.b[i])
					ans.fl=0;
				ans.a[i]=a[i];
				ans.b[i]=b[i];
			}
			else{
				if (tmp.b[i]%a[i]!=b[i])
					ans.fl=0;
				ans.a[i]=tmp.a[i];
				ans.b[i]=tmp.b[i];
			}
		return ans;
	}
}b[N],c[N];
void solve(int l,int r,int &ans){
	For(i,l,r){
		b[i]=node();
		b[i].insert(L[i],a[i]);
	}
	int pos=l,t=l-1;
	node suf=node();
	For(i,l,r){
		suf=suf+b[i];
		for (;pos<=i;){
			for (;pos<=t&&(suf+c[pos]).fl==0;++pos);
			if (pos>i) break;
			if (pos<=t){
				ans=max(ans,i-pos+1);
				break;
			}
			else{
				c[i+1]=node();
				Rep(j,i,pos)
					c[j]=c[j+1]+b[j];
				t=i; suf=node();
			}
		}
		//cout<<i<<' '<<pos<<' '<<t<<endl;
	}
}
void solve(vector<pii> &vec){
	if (!vec.size())
		return puts("0"),void(0);
	int ans=0,l=0;
	for (auto i:vec) a[i.fi]=i.se;
	For(i,1,vec.size()-1)
		if (vec[i].fi!=vec[i-1].fi+1)
			solve(vec[l].fi,vec[i-1].fi,ans),l=i;
	solve(vec[l].fi,vec.back().fi,ans);
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%d",&L[i]);
		For(j,1,L[i]){
			int x;
			scanf("%d",&x);
			vec[x].PB(pii(i,j));
		}
	}
	For(i,1,m) solve(vec[i]);
}