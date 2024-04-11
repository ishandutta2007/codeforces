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
const int N=250;
int a[N+5],ans;
double fac[20005];
double POI(int P){
	double ans=0;
	double v=log(P);
	For(i,1,N)
		if (a[i]<0) return -1e300;
		else ans+=v*a[i]-P-fac[a[i]];
	return ans;
}
double UNI(int P){
	double ans=0;
	double v=log(2*P+1);
	For(i,1,N)
		if (a[i]<0||a[i]>2*P) return -1e300;
		else ans-=v;
	return ans;
}
void solve(){
	double pos=-1e300;
	For(i,1,N) scanf("%d",&a[i]);
	For(i,1,1000){
		For(j,1,N) ++a[j];
		double v1=POI(i),v2=UNI(i);
		//cout<<v2<<endl;
		if (v1>pos) pos=v1,ans=0;
		if (v2>pos) pos=v2,ans=1;
	}
	//cout<<pos<<endl;
	puts(ans?"uniform":"poisson");
}
int main(){
	For(i,1,10000) fac[i]=fac[i-1]+log(i);
	//cout<<fac[200]<<endl;
	int T;
	scanf("%d",&T);
	while (T--) solve();
}