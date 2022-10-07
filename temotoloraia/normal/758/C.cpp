#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=105;
const ll INF=1e18;
ll n,m,k,x,y,minn,maxx,ans,z,t,a[N][N];
int main(){
	cin>>n>>m>>k>>x>>y;
	if (n>1)
	z=(2*n-2)*m;
	else
	z=m;
	minn=k/z;
	maxx=2*minn;
	k%=z;
	for (int j=1;j<=m;j++)
	a[1][j]=minn,a[n][j]=minn;
	for (int i=2;i<n;i++)
	for (int j=1;j<=m;j++)
	a[i][j]=maxx;
	for (int i=1;i<=n&&k;i++)
	for (int j=1;j<=m&&k;j++){
		a[i][j]++;
		k--;
	}
	for (int i=n-1;i>=2&&k;i--)
	for (int j=1;j<=m&&k;j++){
		a[i][j]++;
		k--;
	}
	minn=INF;
	maxx=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (a[i][j]<minn)minn=a[i][j];
		if (a[i][j]>maxx)maxx=a[i][j];
	}
	cout<<maxx<<" "<<minn<<" "<<a[x][y]<<endl;
    return 0;
}