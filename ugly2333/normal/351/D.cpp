//CF 351D
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
const int N = 1e5;
int n,nq;
int b[N+55],ans[N+55];
vector<int> p[N+55],v[N+55],v1[N+55],v2[N+55];
vector<pair<int,int> > q[N+55];
int t[N+55][2],f[N+55];
void addv(int x,int i,int val){
	while(x<=n){
		t[x][i]+=val;
		x+=x&-x;
	}
}
int query(int x,int i){
	int res;
	res=0;
	while(x){
		res+=t[x][i];
		x-=x&-x;
	}
	return res;
}
int main()
{
	int i,j,sz,cnt,x,y;
	scanf("%d",&n);
	for(i=1;i<=N;i=i+1){
		p[i].push_back(0);
		f[i]=n+1;
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",b+i);
		p[b[i]].push_back(i);
	}
	for(i=1;i<=N;i=i+1)
		p[i].push_back(n+1);
	cnt=0;
	for(i=1;i<=N;i=i+1){
		sz=p[i].size();
		if(sz==2)
			continue;
		else
			cnt++;
		for(j=1;j<sz;j=j+1)
			v[p[i][j-1]+1].push_back(p[i][j]-1);
		//cout<<i<<endl;
		x=2;
		for(j=1;j<sz-1;j=j+1){
			while(x<sz-1&&(x<=j||p[i][x]-p[i][x-1]==p[i][x+1]-p[i][x])){
				x++;
			}
			if(x+1<sz){
				v1[p[i][j]].push_back(p[i][x+1]);
				v2[p[i][j-1]].push_back(p[i][x+1]);
			}
		}
	}
	for(i=1;i<=N;i=i+1)
		f[i]=max(f[i],f[i-1]);
	
	scanf("%d",&nq);
	for(i=1;i<=nq;i=i+1){
		scanf("%d%d",&x,&y);
		q[x].push_back(make_pair(y,i));
	}
	
	for(i=1;i<=N;i=i+1){
		sz=v[i].size();
		for(j=0;j<sz;j=j+1)
			if(v[i][j]>=i)
				addv(v[i][j],0,1);
		sz=q[i].size();
		for(j=0;j<sz;j=j+1){
			x=cnt-query(n,0)+query(q[i][j].first-1,0);
			ans[q[i][j].second]=x;
		}
	}
	for(i=N;i>=1;i=i-1){
		sz=v1[i].size();
		for(j=0;j<sz;j=j+1)
			addv(v1[i][j],1,1);
		sz=v2[i].size();
		for(j=0;j<sz;j=j+1)
			addv(v2[i][j],1,-1);
		sz=q[i].size();
		for(j=0;j<sz;j=j+1){
			x=query(q[i][j].first,1);
			if(ans[q[i][j].second]==x)
				ans[q[i][j].second]++;
		}
	}
	for(i=1;i<=nq;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}