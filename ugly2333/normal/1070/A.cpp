//CF1070A
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
int n,m,a[605];
bitset<5005> b[605][505];
void solve(int x,int y,int z){
	if(!x)
		exit(0);
	int i;
	for(i=0;i<=9;i=i+1){
		if(z>=i&&b[x-1][(y-i*a[x]%n+n)%n][z-i]){
			cout<<i;
			solve(x-1,(y-i*a[x]%n+n)%n,z-i);
		}
	}
}
int main()
{
	int i,j,k,x;
	cin>>n>>m;
	a[1]=1;
	for(i=2;i<=600;i=i+1)
		a[i]=a[i-1]*10%n;
	b[0][0][0]=1;
	for(k=1;k<=600;k=k+1){
		for(i=0;i<n;i=i+1)
			for(j=0;j<=9;j=j+1)
				b[k][(i+a[k]*j)%n]|=b[k-1][i]<<j;
		if(b[k][0][m])
			solve(k,0,m);
	}
	cout<<-1;
	return 0;
}