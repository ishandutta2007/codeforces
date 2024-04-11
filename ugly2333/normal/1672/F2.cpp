//CF1672F
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
const int N = 222222;
int n,a[N],b[N],c[N],d[N],e[N];
vector<int> v[N];
queue<int> q;
int main()
{
	int T,i,j,x,o;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			c[i]=0;
		for(i=1;i<=n;i++){
			scanf("%d",a+i);
			c[a[i]]++;
		}
		for(i=1;i<=n;i++)
			scanf("%d",b+i);
		x=0;
		for(i=1;i<=n;i++)
			x=max(x,c[i]);
		for(i=1;i<=n;i++)
			if(c[i]==x)
				o=i;
		for(i=1;i<=n;i++){
			if(a[i]==o||b[i]==o)
				continue;
			v[a[i]].push_back(b[i]);
			e[b[i]]++;
		}
		for(i=1;i<=n;i++)
			d[i]=0;
		for(i=1;i<=n;i++)
			if(c[i]&&!e[i])
				q.push(i);
		while(!q.empty()){
			i=q.front();
			q.pop();
			d[i]=1;
			for(j=0;j<v[i].size();j++){
				x=v[i][j];
				e[x]--;
				if(!e[x])
					q.push(x);
			}
		}
		x=1;
		for(i=1;i<=n;i++)
			if(c[i]&&!d[i])
				x=0;
		if(x)
			printf("AC\n");
		else
			printf("WA\n");
		for(i=0;i<=n+1;i++)
			a[i]=0,b[i]=0,c[i]=0,d[i]=0,e[i]=0,v[i].clear();
	}
	return 0;
}