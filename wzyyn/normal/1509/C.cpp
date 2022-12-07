#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
#define ll long long
using namespace std;

const int N=2005;
int n,a[N];
ll f[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(f,60,sizeof(f));
	For(i,1,n) f[i][i]=0;
	Rep(i,n,1) For(j,i+1,n)
		f[i][j]=min(f[i][j-1],f[i+1][j])+a[j]-a[i];
	cout<<f[1][n]<<endl;
}