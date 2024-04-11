#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,L[2010][2010],R[2010][2010],U[2010][2010],D[2010][2010];
char s[2010][2010];
ll res;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)L[i][j]=(s[i][j]==s[i][j-1]?L[i][j-1]+1:1);
		for(int j=m;j>=1;j--)R[i][j]=(s[i][j]==s[i][j+1]?R[i][j+1]+1:1);
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("(%d,%d)",L[i][j],R[i][j]);puts("");}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		if(s[i][j]!=s[i-1][j])U[i][j]=1;
		else U[i][j]=min(U[i-1][j]+1,min(L[i][j],R[i][j]));
	}
	for(int i=n;i>=1;i--)for(int j=1;j<=m;j++){
		if(s[i][j]!=s[i+1][j])D[i][j]=1;
		else D[i][j]=min(D[i+1][j]+1,min(L[i][j],R[i][j]));
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("(%d,%d)",U[i][j],D[i][j]);puts("");}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)res+=min(U[i][j],D[i][j]);
	printf("%I64d\n",res);
	return 0;
}