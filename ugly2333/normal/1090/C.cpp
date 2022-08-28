//CF1090C
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
int n,m,s[N],a[N],e[N];
vector<int> v[N],t;
pair<int,int> p[N];
void solve(int x,int y,int z){
	int i,o;
	for(i=0;i<s[y];i=i+1)
		e[v[y][i]]=1;
	for(i=s[x]-1;z;i=i-1){
		o=v[x][i];
		if(e[o])
			t.push_back(o);
		else
			v[y].push_back(o),s[y]++,z--,printf("%d %d %d\n",x,y,o);
		v[x][i]=0;
		s[x]--;
	}
	for(i=0;i<s[y];i=i+1)
		e[v[y][i]]=0;
	for(o=t.size();o--;)
		v[x][s[x]++]=t[o];
	t.clear();
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d",&n,&m);
	m=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",s+i);
		for(j=0;j<s[i];j=j+1)
			scanf("%d",&x),v[i].push_back(x);
		p[i]=make_pair(-s[i],i);
		m+=s[i];
	}
	for(i=1;i<=n;i=i+1)
		a[i]=m/n;
	for(i=1;i<=m%n;i=i+1)
		a[i]++;
	sort(p+1,p+n+1);
	x=0;
	for(i=1;i<=n;i=i+1)
		if(s[p[i].second]>a[i])
			x+=s[p[i].second]-a[i];
	printf("%d\n",x);
	i=1,j=n;
	while(i<j){
		x=p[i].second;
		y=p[j].second;
		if(s[x]==a[i]){
			i++;
			continue;
		}
		if(s[y]==a[j]){
			j--;
			continue;
		}
		z=min(s[x]-a[i],a[j]-s[y]);
		solve(x,y,z);
	}
	return 0;
}