//CF1641D
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
#include<unordered_map>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int M = 5;
const int W = 32;
const int B = 2333333;
const int MO1 = 1e9+21;
const int MO2 = 1e9+33;
const int inf = 2e9+N;
int n,m,w,t,a[N][M],b[N][W],c[N],g[N][W],e[W];
unordered_map<LL,int> mp;
pair<int,int> p[N];
vector<int> v[N*W];
int qu(vector<int>&v,int x){
	return upper_bound(v.begin(),v.end(),x)-v.begin();
}
int ok(int x,int y){
	int i,j;
	for(i=0,j=0;i<m&&j<m;){
		if(a[x][i]==a[y][j])
			return 0;
		if(a[x][i]<a[y][j])
			i++;
		else
			j++;
	}
	return 1;
}
int main()
{
	int i,j,k,x,l,r,md,s,ans;
	LL h1,h2,h;
	scanf("%d%d",&n,&m);
	w=1<<m;
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++)
			scanf("%d",b[i]+j);
		sort(b[i],b[i]+m);
		scanf("%d",c+i);
		p[i]=make_pair(c[i],i);
	}
	sort(p+1,p+n+1);
	for(i=1;i<=n;i++){
		x=p[i].second;
		for(j=0;j<m;j++)
			a[i][j]=b[x][j];
		c[i]=p[i].first;
	}
	t=0;
	for(i=1;i<=n;i++){
		for(k=0;k<w;k++){
			h1=B-1,h2=B-1;
			for(j=0;j<m;j++){
				if(k&(1<<j)){
					h1=h1*B+a[i][j];
					h2=h2*B+a[i][j];
					h1%=MO1;
					h2%=MO2;
				}
			}
			h=h1<<32|h2;
			if(mp.find(h)!=mp.end())
				g[i][k]=mp[h];
			else
				mp[h]=++t,g[i][k]=t;
			v[g[i][k]].push_back(i);
		}
	}
	for(k=1;k<w;k++)
		e[k]=e[k>>1]^(k&1);
	ans=inf;
	r=n;
	for(i=1;i<r;){
		s=0;
		for(k=0;k<w;k++){
			x=qu(v[g[i][k]],r);
			if(e[k])
				s-=x;
			else
				s+=x;
		}
		if(s==0)
			i++;
		else{
			while(s){
				if(ok(i,r)){
					ans=min(ans,c[i]+c[r]);
					s--;
				}
				r--;
			}
		}
	}
	if(ans>=inf)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}