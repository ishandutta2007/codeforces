#include"bits/stdc++.h"
#define lowbit(x) ((x)&-(x))
using namespace std;
typedef long long ll;
ll n,k,ans,p;

const int N=2000005;
struct bits{
	ll s[N];bits(){memset(s,0,sizeof(s));}
	void add(int x,ll u){while(x<=2*n+2)s[x]+=u,x+=lowbit(x);}
	ll qry(int x){ll r=0;while(x)r+=s[x],x-=lowbit(x);return r;}
} a,b;
inline void add(int l,int r,ll u){
	a.add(l,u);a.add(r+1,-u);
	b.add(l,u*l);b.add(r+1,-u*r-u);
}
inline ll qry(int x){return a.qry(x)*(x+1)-b.qry(x);}
inline ll qryb(int x){
	if(x<=n)return qry(x)+qry(x+n);
	return qry(x)+qry(x-n);
}

int main(){
	scanf("%d%d",&n,&k);ans=p=1;
	if(k>n/2)k=n-k;
	for(int i=1;i<=n;i++){
		int nx=p+k;
		if(nx<=n){
			ans+=qryb(nx)-qryb(p)+1;
			add(p+1,p+1,1);add(nx,nx,1);
		}else{
			ans+=qryb(n)-qryb(p)+qryb(nx)-qry(n)+1;
			add(p+1,p+1,1),add(nx,nx,1);
		}
		printf("%I64d ",ans);
		p=nx%n;if(p==0)p=n;
	}
	return 0;
}