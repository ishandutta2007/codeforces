//CF1693C
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
int n,m,d[N],e[N],h[N];
vector<int> v[N];
priority_queue<pair<int,int> > q;
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		v[y].push_back(x);
		e[x]++;
	}
	for(i=1;i<=n;i++)
		d[i]=N,h[i]=0;
	d[n]=0;
	q.push(make_pair(0,n));
	while(!q.empty()){
		x=q.top().second;
		q.pop();
		if(h[x])
			continue;
		h[x]=1;//cout<<x<<' '<<d[x]<<endl;
		for(i=0;i<v[x].size();i++){
			y=v[x][i];
			if(!h[y]){
				e[y]--;
				z=d[x]+e[y]+1;
				if(d[y]>z){
					d[y]=z;
					q.push(make_pair(-z,y));
				}
			}
		}
	}
	printf("%d\n",d[1]);
	return 0;
}