//CF 835D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
char c[5555];
bool a[5555][5555];
int f[5555][5555],ans[5555];
int main()
{
	int n,i,j,x,y;
	scanf("%s",&c);
	n=strlen(c);
	for(i=0;i<n;i=i+1){
		for(j=0;j<=i;j=j+1)
			a[i][j]=1;
		f[i][i]=1;
		ans[1]++;
	}
	for(i=1;i<n;i=i+1){
		for(j=0;i+j<n;j=j+1)
			if(c[j]==c[i+j]&&a[j+1][i+j-1])
				a[j][i+j]=1;
	}
	for(i=1;i<n;i=i+1)
		for(j=0;i+j<n;j=j+1){
			if(!a[j][i+j]){
				f[j][i+j]=0;
				continue;
			}
			x=(j+i+j)/2;
			y=x+1;
			if(i%2==0)
				x--;
			//cout<<j<<i+j<<x<<y<<endl;
			f[j][i+j]=min(f[j][x],f[y][i+j])+1;
			ans[f[j][i+j]]++;
		}
	for(i=n;i>=1;i=i-1)
		ans[i]+=ans[i+1];
	for(i=1;i<=n;i=i+1)
		printf("%d ",ans[i]);
	return 0;
}