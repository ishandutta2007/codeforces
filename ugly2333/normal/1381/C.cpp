//CF1381C
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
int n,x,y,a[N],b[N],s[N];
vector<int> v[N];
priority_queue<pair<int,int> > Q;
vector<pair<int,int> > e;
int main()
{
	int T,i,j,k,o,u;
	pair<int,int> p;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&x,&y);
		for(i=1;i<=n;i=i+1){
			scanf("%d",a+i);
			v[a[i]].push_back(i);
			s[a[i]]++;
		}
		for(i=1;i<=n+1;i=i+1)
			Q.push(make_pair(s[i],i));
		for(i=1;i<=n+1;i=i+1)
			if(!s[i])
				o=i;
		for(j=1;j<=x;j=j+1){
			p=Q.top();
			Q.pop();
			i=p.second;
			s[i]--;
			b[v[i][s[i]]]=i;
			p.first--;
			Q.push(p);
		}
		for(i=1;i<=n;i=i+1)
			if(!b[i])
				e.push_back(make_pair(a[i],i));
		sort(e.begin(),e.end());
		j=e.size();
		for(i=0;i<j;i=i+1)
			b[e[i].second]=e[(i+j/2)%j].first;
		u=n-y;
		for(i=0;i<j;i=i+1){
			k=e[i].second;
			if(a[k]==b[k])
				b[k]=o,u--;
		}
		for(i=0;u>=1;i=i+1){
			k=e[i].second;
			if(b[k]!=o)
				b[k]=o,u--;
		}
		if(u==0){
			printf("YES\n");
			for(i=1;i<=n;i=i+1)
				printf("%d ",b[i]);
			printf("\n");
		}
		else
			printf("NO\n");
		for(i=0;i<=n+1;i=i+1)
			a[i]=0,b[i]=0,s[i]=0,v[i].clear();
		e.clear();
		while(!Q.empty()){
			Q.pop();
		}
	}
	return 0;
}