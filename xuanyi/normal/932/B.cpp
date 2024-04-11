#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1000005;
int Q,l,r,k,f[MAXN],g[MAXN],s[MAXN][10];
inline int calc(int x){
	int s=1;
	while (x){
		if (x%10) s=s*(x%10);
		x/=10; 
	}
	return s;
}
int main(){
	for (int i=1;i<MAXN;i++) f[i]=calc(i);
	for (int i=1;i<10;i++) g[i]=i;
	for (int i=10;i<MAXN;i++) g[i]=g[f[i]];
	for (int i=1;i<MAXN;i++)
	for (int j=1;j<10;j++)
		s[i][j]=s[i-1][j]+(g[i]==j);
	scanf("%d",&Q);
	while (Q--){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}