#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n,k,mx,e[1005][1005];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			int px=i-1,py=j-1,t=0;
			for (;px!=py;px/=k,py/=k,++t);
			e[i][j]=t;
			mx=max(mx,t);
		}
	printf("%d\n",mx);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			printf("%d ",e[i][j]);
}