#include "bits/stdc++.h"
using namespace std;
long long k,ans,tim,mx,mn;
long long a[105][105];
int n,m,x,y;
int main(){
	cin>>n>>m>>k>>x>>y;
	if (n==2) y+=(x-1)*m, x=1, m*=2, n/=2;
	if (n==1){
		tim = k/m; k %= m;
		printf("%I64d %I64d %I64d\n",tim+(k!=0),tim,tim+(y<=k));
		return 0;
	}
	tim = k / ((2*n-2)*m); k%=((2*n-2)*m);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++){
			a[i][j] = (i==1||i==n)? tim : tim*2;
		}
	}
	if (k>=n*m){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]++,k--;
		for(int i=n-1;i>=1;i--)
			for(int j=1;j<=m&&k;j++)
				a[i][j]++,k--;
	} else {
		for(int i=1;i<=n&&k;i++)
			for(int j=1;j<=m&&k;j++)
				a[i][j]++,k--;
	}
	mx = 0, mn = a[1][1];
	for (int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		mx = max(mx,a[i][j]), mn = min(mn,a[i][j]);
	printf ("%I64d %I64d %I64d\n",mx,mn,a[x][y]);
	return 0;
}