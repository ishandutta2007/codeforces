//CF1487F
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
const int N = 255;
const int inf = 1e9;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
int n,b=250,a[N],f[55][N*2][N*2];
char s[N];
int main()
{
	int i,j,k,l,x,y;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i=i+1)
		a[i]=s[i]-'0';
	for(i=0;i<=n;i=i+1)
		for(j=-b;j<=b;j=j+1)
			for(k=-b;k<=b;k=k+1)
				f[i][N+j][N+k]=inf;
	f[0][N][N]=0;
	f[0][N+1][N-1]=n+1;
	for(i=0;i<n;i=i+1){
		for(j=-b;j<=b;j=j+1){
			for(k=-b;k<=b;k=k+1){
				if(f[i][N+j][N+k]>=inf)
					continue;
				for(l=-b;l<=b;l=l+1){
					x=a[i+1]+k*10-l;
					y=abs(l-j)*(n-i);
					if(-b<=x&&x<=b)
						cmin(f[i+1][N+l][N+x],f[i][N+j][N+k]+y);
				}
			}
		}
	}
	x=inf;
	for(j=-b;j<=b;j=j+1)
		cmin(x,f[n][N+j][N]);
	printf("%d",x);
	return 0;
}