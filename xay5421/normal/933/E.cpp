#include<bits/stdc++.h>
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=300005;
int n,a[N],g[N];
LL f[N];
int main(){
	memset(f,63,sizeof(f));
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	f[0]=0;
	rep(i,1,n){
		LL w1=f[max(i-2,0)]+a[i];
		LL w2=f[max(i-3,0)]+max(a[i],a[i-1]);
		if(w1<w2){
			f[i]=w1;
		}else{
			f[i]=w2;
			g[i]=1;
		}
	}
	vector<pair<int,int> >ans;
	auto fun=[&](int x){
		if(x>=1){
			int t=min(a[x],a[x+1]);
			a[x]-=t,a[x+1]-=t;
			if(t){
				ans.EB(x,t);
			}
		}
	};
	for(int i=n-(f[n-1]<f[n]);i>=1;i-=2+g[i]){
		fun(i-1);
		if(g[i])fun(i-2);
		fun(i);
	}
	printf("%d\n",SZ(ans));
	for(auto x:ans)printf("%d\n",x.X);
	return 0;
}