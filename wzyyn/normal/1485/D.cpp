#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
int n,m,a[505][505];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m)
		if ((i+j)&1) a[i][j]=720720;
		else a[i][j]=720720+a[i][j]*a[i][j]*a[i][j]*a[i][j];
	For(i,1,n) For(j,1,m)
		printf("%d%c",a[i][j],j==m?'\n':' ');
}