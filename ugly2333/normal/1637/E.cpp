//CF1637E
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
int n,m;
LL b[N],ans;
map<int,int> mp;
map<int,int>::iterator it;
vector<int> v[N],e;
bool inb(int x,int y){
	if(x>y)
		swap(x,y);
	LL s=(LL)x<<32|y;
	return (*lower_bound(b+1,b+m+1,s))==s;
}
int h[N];
priority_queue<pair<int,int> > q;
void go1(int x){
	if(v[x].size()<=1)
		return;
	int i,l=v[x].size();
	for(i=0;i<l;i++)
		h[i]=i+1;
	while(!q.empty()){
		q.pop();
	}
	for(i=0;i<l;i++)
		if(h[i]<l)
			q.push(make_pair(v[x][i]+v[x][h[i]],i));
	while(!q.empty()){
		i=q.top().second;
		q.pop();
		if(!inb(v[x][i],v[x][h[i]])){
			ans=max(ans,(LL)(v[x][i]+v[x][h[i]])*(x+x));
			return;
		}
		h[i]++;
		if(h[i]<l)
			q.push(make_pair(v[x][i]+v[x][h[i]],i));
	}
}
void go2(int x,int y){
	int i,l1=v[x].size(),l2=v[y].size();
	for(i=0;i<l1;i++)
		h[i]=0;
	while(!q.empty()){
		q.pop();
	}
	for(i=0;i<l1;i++)
		if(h[i]<l2)
			q.push(make_pair(v[x][i]+v[y][h[i]],i));
	while(!q.empty()){
		i=q.top().second;
		q.pop();
		if(!inb(v[x][i],v[y][h[i]])){
			ans=max(ans,(LL)(v[x][i]+v[y][h[i]])*(x+y));
			return;
		}
		h[i]++;
		if(h[i]<l2)
			q.push(make_pair(v[x][i]+v[y][h[i]],i));
	}
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		mp.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			mp[x]++;
		}
		for(it=mp.begin();it!=mp.end();it++)
			v[(*it).second].push_back((*it).first);
		for(i=1;i<=n;i++)
			if(v[i].size())
				e.push_back(i),reverse(v[i].begin(),v[i].end());
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(x>y)
				swap(x,y);
			b[i]=(LL)x<<32|y;
		}
		sort(b+1,b+m+1);
		b[m+1]=0;
		ans=0;
		for(x=0;x<e.size();x++)
			go1(e[x]);
		for(x=0;x<e.size();x++)
			for(y=x+1;y<e.size();y++)
				go2(e[x],e[y]);
		printf("%lld\n",ans);
		for(i=1;i<=n;i++)
			v[i].clear();
		e.clear();
	}
	return 0;
}