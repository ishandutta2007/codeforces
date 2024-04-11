//CF 650C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 1e6+16;
vector<pair<int,int> > r[N],c[N];
vector<int> v[N];
int f[N],indeg[N],ans[N];
queue<int> Q;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int n,m,i,j,s,x;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i=i+1)
		for(j=0;j<m;j=j+1){
			scanf("%d",&x);
			r[i].push_back(make_pair(x,i*m+j));
			c[j].push_back(make_pair(x,i*m+j));
			f[i*m+j]=i*m+j;
		}
	
	for(i=0;i<n;i=i+1){
		sort(r[i].begin(),r[i].end());
		for(j=1;j<m;j=j+1){
			if(r[i][j-1].first==r[i][j].first)
				f[fnd(r[i][j-1].second)]=fnd(r[i][j].second);
		}
	}
	for(j=0;j<m;j=j+1){
		sort(c[j].begin(),c[j].end());
		for(i=1;i<n;i=i+1){
			if(c[j][i-1].first==c[j][i].first)
				f[fnd(c[j][i-1].second)]=fnd(c[j][i].second);//cout<<c[j][i].second<<endl;
		}
	}
	
	for(i=0;i<n;i=i+1){
		for(j=1;j<m;j=j+1){
			if(r[i][j-1].first!=r[i][j].first){
				v[fnd(r[i][j-1].second)].push_back(fnd(r[i][j].second));
				//cout<<r[i][j-1].second<<r[i][j].second<<endl;
				indeg[fnd(r[i][j].second)]++;
			}
		}
	}
	for(j=0;j<m;j=j+1){
		for(i=1;i<n;i=i+1){
			if(c[j][i-1].first!=c[j][i].first){
				v[fnd(c[j][i-1].second)].push_back(fnd(c[j][i].second));
				//cout<<c[j][i-1].second<<c[j][i].second<<endl;
				indeg[fnd(c[j][i].second)]++;
			}
		}
	}
	for(i=0;i<n*m;i=i+1){
		if(i==fnd(i)&&!indeg[i]){
			ans[i]=1;
			Q.push(i);
		}
		//cout<<i<<f[i]<<endl;
	}
	while(!Q.empty()){
		x=Q.front();
		//cout<<x<<endl;
		Q.pop();
		s=v[x].size();
		for(i=0;i<s;i=i+1){
			j=v[x][i];
			ans[j]=max(ans[j],ans[x]+1);
			indeg[j]--;
			if(!indeg[j])
				Q.push(j);
		}
	}
	for(i=0;i<n;i=i+1){
		for(j=0;j<m;j=j+1)
			printf("%d ",ans[fnd(i*m+j)]);
		printf("\n");
	}
	return 0;
}