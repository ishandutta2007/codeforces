//CF1450G
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
const int N = 33;
const int W = 1<<20;
const int M = 5555;
int n,w,m,a,b,l[N],r[N],c[N],d[N],g[N],h[N];
bool f[W];
char s[M];
pair<pair<int,int>,pair<int,int> > p[N];
vector<int> v;
int main()
{
	int i,j,x,y,z;
	scanf("%d%d%d%s",&m,&a,&b,s+1);
	for(i=0;i<26;i=i+1)
		l[i]=m+1,r[i]=0;
	for(i=1;i<=m;i=i+1){
		x=s[i]-'a';
		l[x]=min(l[x],i);
		r[x]=max(r[x],i);
		c[x]++;
	}
	for(i=0;i<26;i=i+1)
		p[i]=make_pair(make_pair(l[i],r[i]),make_pair(c[i],i));
	sort(p,p+26);
	for(i=0;i<26;i=i+1)
		if(l[i]<=m)
			n++;
	w=1<<n;
	for(i=0;i<n;i=i+1){
		l[i]=p[i].first.first;
		r[i]=p[i].first.second;
		c[i]=p[i].second.first;
		d[i]=p[i].second.second;
		g[i]=(1<<i)-1;
		h[i]=w-(1<<i);
	}
	f[0]=1;
	for(i=1;i<w;i=i+1){
		for(j=1;j<n;j=j+1)
			f[i]|=f[i&g[j]]&f[i&h[j]];
		x=m+1,y=0,z=0;
		for(j=0;j<n;j=j+1){
			if(i&(1<<j)){
				x=min(x,l[j]);
				y=max(y,r[j]);
				z+=c[j];
			}
		}
		if((y-x+1)*a>z*b)
			continue;
		for(j=0;j<n;j=j+1)
			if(i&(1<<j))
				f[i]|=f[i^(1<<j)];
	}
	for(i=0;i<n;i=i+1)
		if(f[(w-1)^(1<<i)])
			v.push_back(d[i]);
	sort(v.begin(),v.end());
	printf("%d",v.size());
	for(i=0;i<v.size();i=i+1)
		printf(" %c",v[i]+'a');
	return 0;
}