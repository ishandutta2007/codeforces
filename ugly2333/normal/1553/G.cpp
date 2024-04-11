//CF1553G
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
const int N = 1111111;
int n,q,m,pr[N],a[N],f[N];
vector<int> v[N],e[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void ade(int x,int y){
	if(x==y)
		return;
	e[x].push_back(y);
	e[y].push_back(x);
}
int main()
{
	int i,j,k,x,y;
	m=1e6+1;
	for(i=2;i<=m;i++){
		if(v[i].size())
			continue;
		pr[i]=1;
		for(j=i;j<=m;j+=i)
			v[j].push_back(i);
	}
	scanf("%d%d",&n,&q);
	for(i=1;i<=m;i++)
		f[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(pr[a[i]])
			continue;
		x=v[a[i]][0];
		for(j=1;j<v[a[i]].size();j++)
			f[fnd(v[a[i]][j])]=fnd(x);
	}
	for(i=1;i<=n;i++){
		x=v[a[i]][0];
		for(j=0;j<v[a[i]+1].size();j++){
			ade(fnd(x),fnd(v[a[i]+1][j]));
			for(k=0;k<j;k++)
				ade(fnd(v[a[i]+1][j]),fnd(v[a[i]+1][k]));
		}
	}
	for(i=1;i<=m;i++)
		sort(e[i].begin(),e[i].end()),e[i].push_back(N);
	for(i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		x=fnd(v[a[x]][0]);
		y=fnd(v[a[y]][0]);
		if(x==y)
			printf("0\n");
		else{
			if(*lower_bound(e[x].begin(),e[x].end(),y)==y)
				printf("1\n");
			else
				printf("2\n");
		}
	}
	return 0;
}