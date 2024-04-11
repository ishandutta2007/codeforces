//
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
const int N = 111111;
const int M = 555;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int n,m,a[N],b[N],c[N],e[N],f[M][M],u[M];
vector<int> v[N],r[N];
queue<int> q;
int main()
{
	int i,j,k,x,y,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		r[y].push_back(x);
		b[x]++;
	}
	for(i=1;i<=n;i=i+1)
		if(!b[i])
			q.push(i);
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(i=0;i<v[x].size();i=i+1)
			e[a[v[x][i]]]++;
		for(a[x]=0;e[a[x]];a[x]++);
		for(i=0;i<v[x].size();i=i+1)
			e[a[v[x][i]]]--;
		for(i=0;i<r[x].size();i=i+1){
			y=r[x][i];
			b[y]--;
			if(!b[y])
				q.push(y);
		}
	}
	for(i=1;i<=n;i=i+1)
		c[a[i]]++;
	x=0;
	for(i=1;i<=n;i=i+1)
		x=max(x,a[i]);
	for(m=1;m<=x;m<<=1);
	for(i=0;i<m;i=i+1){
		ad(f[i][i],MO-(n+1));
		for(j=0;j<m;j=j+1)
			ad(f[i][i^j],c[j]);
		if(i)
			ad(f[i][m],1);
	}
	/*for(i=0;i<m;i=i+1){
		for(j=0;j<=m;j=j+1)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}*/
	for(i=0;i<m;i=i+1){
		for(j=0;j<m;j=j+1)
			if(!u[j]&&f[j][i])
				o=j;
		u[o]=1;
		x=fpow(f[o][i]);
		for(k=0;k<=m;k=k+1)
			f[o][k]=mul(f[o][k],x);
		for(j=0;j<m;j=j+1){
			if(j==o)
				continue;
			x=MO-f[j][i];
			for(k=0;k<=m;k=k+1)
				ad(f[j][k],mul(f[o][k],x));
		}
	}
	/*for(i=0;i<m;i=i+1){
		for(j=0;j<=m;j=j+1)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}*/
	for(i=0;i<m;i=i+1)
		if(f[i][0])
			x=MO-f[i][m];
	ad(x,0);
	printf("%d",x);
	return 0;
}