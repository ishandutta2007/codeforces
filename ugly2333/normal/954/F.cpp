//CF954F
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
const int N = 22222;
const int MO = 1e9+7;
struct node{
	int a[3][3];
	node(int x=0){
		int i,j;
		memset(a,0,sizeof(a));
		for(i=0;i<3;i=i+1)
			for(j=0;j<3;j=j+1)
				if(x&(1<<j))
					if((i^j)!=2)
						a[i][j]=1;
	}
}e[11],one,cur;
node mul(node x,node y){
	node z;
	int i,j,k;
	for(i=0;i<3;i=i+1)
		for(j=0;j<3;j=j+1)
			for(k=0;k<3;k=k+1)
				z.a[i][j]+=(LL)x.a[i][k]*y.a[k][j]%MO,z.a[i][j]%=MO;
	return z;
}
node fpow(node x,LL y){
	if(!y)
		return one;
	node z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int n,c[N],s[3];
LL m,l[N],r[N],p[N];
map<LL,int> M;
map<LL,int>::iterator it;
vector<int> v[N];
int main()
{
	int i,j,x;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d%lld%lld",c+i,l+i,r+i);
		r[i]++;
		M[l[i]]=1;
		M[r[i]]=1;
	}
	M[2]=1,M[m+1]=1;
	x=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++x,p[x]=(*it).first;
	for(i=1;i<=n;i=i+1){
		v[M[l[i]]].push_back(c[i]);
		v[M[r[i]]].push_back(-c[i]);
	}
	for(i=0;i<3;i=i+1)
		one.a[i][i]=1;
	for(i=0;i<8;i=i+1)
		e[i]=node(i);
	cur=one;
	n=x;
	for(i=1;i<n;i=i+1){
		for(j=v[i].size();j--;){
			x=v[i][j];
			if(x>0)
				s[x-1]++;
			else
				s[-x-1]--;
		}
		x=0;
		for(j=0;j<3;j=j+1)
			if(!s[j])
				x|=1<<j;
		cur=mul(cur,fpow(e[x],p[i+1]-p[i]));
	}
	cout<<cur.a[1][1];
	return 0;
}