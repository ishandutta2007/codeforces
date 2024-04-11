//CF 1152F2
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
const int N = 222;
const int MO = 1e9+7;
int mul(int x,int y){
	return (LL)x*y%MO;
}
struct node{
	int a[N][N];
}b,c;
int n;
LL w[N][N];
node operator*(node p,node q){
	node r;
	int i,j,k;
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			for(k=0;k<n;k=k+1)
				w[i][k]+=mul(p.a[i][j],q.a[j][k]);
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			r.a[i][j]=w[i][j]%MO,w[i][j]=0;
	return r;
}
int l,k,m;
int main()
{
	int i,j,x,y,z;
	LL s;
	cin>>l>>k>>m;
	n=(k+1)<<m;
	for(i=0;i<n;i=i+1){
		x=i>>m;
		y=i-(x<<m);
		z=0;
		for(j=0;j<m;j=j+1)
			if(y&(1<<j))
				z++;
		y>>=1;
		b.a[i][x<<m|y]=1;
		if(x==k)
			continue;
		x++;
		y|=1<<(m-1);
		b.a[i][x<<m|y]=z+1;
	}
	for(i=0;i<n;i=i+1)
		c.a[i][i]=1;
	while(l){
		if(l&1)
			c=c*b;
		b=b*b;
		l>>=1;
	}
	s=0;
	for(i=0;i<(1<<m);i=i+1)
		s+=c.a[0][k<<m|i];
	cout<<s%MO;
	return 0;
}