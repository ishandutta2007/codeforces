#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define double long double
using namespace std;
const int N=5005;
int n,a[N],s[N];
long long f[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&s[i]);
	For(i,1,n) f[i]=0;
	For(i,1,n) Rep(j,i-1,1)
		if (a[i]!=a[j]){
			long long v=f[j];
			f[j]=max(f[j],f[i]+abs(s[i]-s[j]));
			f[i]=max(f[i], v  +abs(s[i]-s[j]));
		}
	long long ans=0;
	For(i,1,n) ans=max(ans,f[i]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}