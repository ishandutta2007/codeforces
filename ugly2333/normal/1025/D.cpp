//Cf 1025D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 777;
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int n,a[N],e[N][N],f[N][N][2];
int main()
{
	int i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	a[0]=0,a[n+1]=0;
	for(i=0;i<=n+1;i=i+1)
		for(j=0;j<=n+1;j=j+1)
			e[i][j]=gcd(a[i],a[j])!=1;
	for(i=0;i<=n+1;i=i+1)
		for(j=0;j<i;j=j+1)
			f[i][j][0]=1,f[i][j][1]=1;
	for(i=1;i<=n;i=i+1)
		f[i][i][0]=e[i][i-1],f[i][i][1]=e[i][i+1];
	for(l=2;l<=n;l=l+1){
		for(i=1,j=l;j<=n;i=i+1,j=j+1){
			for(k=i;k<=j;k=k+1){
				if(f[i][k-1][1]&&f[k+1][j][0]){
					if(e[k][i-1])
						f[i][j][0]=1;
					if(e[k][j+1])
						f[i][j][1]=1;
				}
			}
		}
	}
	if(f[1][n][0]||f[1][n][1])
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}