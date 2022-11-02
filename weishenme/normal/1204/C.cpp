#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=105,M=1000005;
char s[N];
int a[N][N],v[M],p[M],b[M],n,m;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=n;j++){
			if (i==j)a[i][j]=0;
			else if (s[j]=='1')a[i][j]=1;
			else a[i][j]=1e9;
		}
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)scanf("%d",&p[i]);
	v[1]=p[1];v[2]=p[2];int tot=2;
	for (int i=3;i<=m;i++){
		while (tot>=2&&a[v[tot-1]][p[i]]==a[v[tot-1]][v[tot]]+a[v[tot]][p[i]])tot--;
		v[++tot]=p[i];
	}		
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++)printf("%d ",v[i]);
	return 0;
}