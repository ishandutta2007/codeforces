//CF 838E
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
int n;
double a[2555],b[2555],ans;
double f[2555][2555],g[2555][2555];
double dist(int i,int j){
	return sqrt((double)(a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
}
int pre(int x){
	return (x+n-1)%n;
}
int nex(int x){
	return (x+1)%n;
}
int main()
{
	int i,l,x,y;
	cin>>n;
	for(i=0;i<n;i=i+1){
		cin>>a[i]>>b[i];
		f[i][i]=0;
		g[i][i]=0;
	}
	for(l=1;l<n;l=l+1){
		for(i=0;i<n;i=i+1){
			x=i;
			y=(i+l)%n;
			//cout<<nex(x)<<pre(y)<<endl;
			f[x][y]=max(f[nex(x)][y]+dist(x,nex(x)),g[nex(x)][y]+dist(x,y));
			g[x][y]=max(g[x][pre(y)]+dist(pre(y),y),f[x][pre(y)]+dist(x,y));
		}
	}
	ans=0;
	for(i=0;i<n;i=i+1)
		ans=max(ans,max(f[i][i-1],g[i][i-1]));
	printf("%.12lf",ans);
	return 0;
}