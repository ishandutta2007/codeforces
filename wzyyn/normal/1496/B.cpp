#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
int n,k;
int a[100005];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int mex=0;
	for (;mex<n&&a[mex+1]==mex;++mex);
	if ((mex+a[n]+1)/2>a[n])
		printf("%d\n",n+k);
	else{
		int v=(mex+a[n]+1)/2;
		int p=lower_bound(a+1,a+n+1,v)-a;
		if (a[p]!=v&&k) ++n;
		printf("%d\n",n);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}