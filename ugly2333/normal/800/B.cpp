//CF ###
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
double x[1111],y[1111],ans,s,a,b,c,p;
double dis(int u,int v){
	return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}
double are(int u,int v,int w)
{
	return abs((x[w]-x[u])*(y[v]-y[u])-(x[v]-x[u])*(y[w]-y[u]));
}
int main()
{
	int n,i;
	ans=1e11;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		cin>>x[i]>>y[i];
	x[n+1]=x[1],y[n+1]=y[1];
	x[n+2]=x[2],y[n+2]=y[2];
	for(i=1;i<=n;i=i+1){
		c=dis(i,i+2);
		s=are(i,i+1,i+2);
		ans=min(ans,s/c);
	}
	printf("%.9f",ans/2.0);
	return 0;
}