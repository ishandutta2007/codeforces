#include<bits/stdc++.h>

using namespace std;

const int N=1005;

double f[N][N];
bool vis[N][N];
int n,m;

double dfs(int n,int m){
	if(vis[n][m])return f[n][m];
	vis[n][m]=true;
	if(!m)return f[n][m]=1;
	double inv=1.0/(m+1);
	if(!n)return f[n][m]=inv;
	double a=1-dfs(m,n-1),b=1,d=m*inv*(1-dfs(m-1,n)),c=inv+d;
	double p=1/((c-a)/(b-d)+1);
	return f[n][m]=p*a+(1-p)*b;
}

int main(){
	scanf("%d%d",&n,&m);
	double ans=dfs(n,m);
	printf("%.11lf %.11lf\n",ans,1-ans);
	return 0;
}