//CF 201D
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
typedef double DB;
const int N = 16;
const int W = 1<<N;
const int K = 555555;
const int inf = 1e9;
int n,w,m,k,a[K],b[K][N],c[W][N],f[W][N*N];
string s[N],t;
void cmin(int& x,int y){
	if(x>y)
		x=y;
}
int main()
{
	int T=0,i,j,o,x,ans=inf,anss=0;
	cin>>n;
	for(i=0;i<n;i=i+1)
		cin>>s[i];
	w=(1<<n)-1;
	for(i=0;i<=w;i=i+1){
		for(j=n-1;j>=0;j=j-1){
			c[i][j]=c[i][j+1];
			if(i&(1<<j))
				c[i][j]++;
		}
	}
	scanf("%d",&m);
	while(m--){
		T++;
		cin>>k;
		for(i=0;i<=k;i=i+1)
			a[i]=-1;
		for(i=1;i<=k;i=i+1){
			cin>>t;
			for(j=0;j<n;j=j+1)
				if(t==s[j])
					a[i]=j;
		}
		memset(b,0,sizeof(b));
		for(i=k;i>=0;i=i-1){
			for(j=0;j<n;j=j+1)
				b[i][j]=b[i+1][j];
			if(a[i]>=0)
				b[i][a[i]]=i;
		}
		for(i=0;i<=w;i=i+1)
			for(j=0;j<n*n;j=j+1)
				f[i][j]=inf;
		f[0][0]=0;
		for(i=0;i<=w;i=i+1)
			for(j=0;j<n*n;j=j+1){
				x=f[i][j];
				if(x>=inf)
					continue;
				for(o=0;o<n;o=o+1){
					if(i&(1<<o))
						continue;
					if(b[x][o])
						cmin(f[i|(1<<o)][j+c[i][o]],b[x][o]);
				}
			}
		for(j=0;j<n*n;j=j+1)
			if(f[w][j]<=k&&j<ans)
				ans=j,anss=T;
	}
	if(ans>=inf){
		cout<<"Brand new problem!";
		return 0;
	}
	ans=n*(n-1)/2-ans+1;
	cout<<anss<<endl;
	cout<<"[:";
	while(ans--){
		cout<<'|';
	}
	cout<<":]";
	return 0;
}