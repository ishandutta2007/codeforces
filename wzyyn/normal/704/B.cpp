#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=5005;
int n,S,T;
ll x[N],a[N],b[N],c[N],d[N],ans;
priority_queue<ll,vector<ll>,greater<ll> > Q;
ll F(int i,int j){
	if (i==j) return 0;
	if (j<i) return 1ll*x[i]-x[j]+c[i]+b[j];
	if (j>i) return 1ll*x[j]-x[i]+d[i]+a[j];
}
int main(){
	scanf("%d%d%d",&n,&S,&T);
	For(i,1,n) scanf("%lld",&x[i]);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) scanf("%lld",&b[i]);
	For(i,1,n) scanf("%lld",&c[i]);
	For(i,1,n) scanf("%lld",&d[i]);
	ans=F(S,1)+F(1,T);
	For(i,2,n){
		ll A=x[i]+a[i],B=-x[i]+b[i];
		ll C=x[i]+c[i],D=-x[i]+d[i];
		if (i==S){
			Q.push(D-C);
			continue;
		}
		if (i==T){
			Q.push(B-A);
			continue;
		}
		if (i<S) Q.push(B-A);
		if (i<T) Q.push(D-C);
		ans+=A+C+Q.top(); Q.pop();
		if (i>S) Q.push(B-A);
		if (i>T) Q.push(D-C);
	}
	printf("%lld\n",ans);
}