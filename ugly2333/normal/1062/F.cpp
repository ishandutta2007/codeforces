//CF1062F
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
const int N = 333333;
int n,m,a[N],b[N],c[N],d[N],e[N],f[N],h[N];
vector<int> v[N],r[N];
queue<int> q;
int main()
{
	int i,j,x,y,o,s,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		r[y].push_back(x);
		b[x]++;
		c[y]++;
	}
	for(x=1;x<=n;x=x+1)
		if(!c[x])
			q.push(x);
	o=0;
	while(!q.empty()){
		x=q.front();
		q.pop();
		a[++o]=x;
		for(i=v[x].size();i--;){
			y=v[x][i];
			c[y]--;
			if(!c[y])
				q.push(y);
		}
	}
	for(x=1;x<=n;x=x+1)
		d[x]=0,e[x]=0,f[x]=0;
	s=0,t=0;
	for(j=1;j<=n;j=j+1){
		x=a[j];
		for(i=r[x].size();i--;){
			y=r[x][i];
			if(d[y]){
				d[y]=0,s--,t^=y;
				e[x]++,f[y]=x;
			}
			else{
				if(f[y])
					e[f[y]]--;
				f[y]=0;
			}
		}
		if(s>1||(s&&e[t]))
			h[x]+=2;
		else
			h[x]+=s;
		d[x]=1,s++,t^=x;
	}
	for(x=1;x<=n;x=x+1)
		d[x]=0,e[x]=0,f[x]=0;
	s=0,t=0;
	for(j=n;j;j=j-1){
		x=a[j];
		for(i=v[x].size();i--;){
			y=v[x][i];
			if(d[y]){
				d[y]=0,s--,t^=y;
				e[x]++,f[y]=x;
			}
			else{
				if(f[y])
					e[f[y]]--;
				f[y]=0;
			}
		}
		if(s>1||(s&&e[t]))
			h[x]+=2;
		else
			h[x]+=s;
		d[x]=1,s++,t^=x;
	}
	s=0;
	for(x=1;x<=n;x=x+1)
		if(h[x]<=1)
			s++;
	cout<<s;
	return 0;
}