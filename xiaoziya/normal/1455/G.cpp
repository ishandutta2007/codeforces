#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;
const int maxn=200005;
int n,ban,tot,top;
int stk[maxn];
vector< pair<int,int> >v[maxn];
string s;
long long ans;
long long tag[maxn];
map<int,long long>f[maxn];
multiset<long long>g[maxn];
void dfs(int x){
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i].first,z=v[x][i].second;
		if(y>0){
			if(f[x].count(z)){
				f[y][z]=0,g[y].insert(0),dfs(y);
				long long rec=f[x][z];
				f[x].erase(z),g[x].erase(g[x].find(rec));
				if(f[y].size()>f[x].size()){
					tag[x]+=tag[y]+rec;
					for(map<int,long long>::iterator it=f[x].begin();it!=f[x].end();it++){
						int a=it->first;
						long long b=it->second-tag[y]-rec;
						if(f[y].count(a))
							g[y].erase(g[y].find(f[y][a])),f[y][a]=min(f[y][a],b),g[y].insert(f[y][a]);
						else f[y][a]=b,g[y].insert(f[y][a]);
					}
					swap(f[x],f[y]),swap(g[x],g[y]);
				}
				else for(map<int,long long>::iterator it=f[y].begin();it!=f[y].end();it++){
					int a=it->first;
					long long b=rec+it->second+tag[y];
					if(f[x].count(a))
						g[x].erase(g[x].find(f[x][a])),f[x][a]=min(f[x][a],b),g[x].insert(f[x][a]);
					else f[x][a]=b,g[x].insert(f[x][a]);
				}
			}
		}
		else{
			y=-y,tag[x]+=z;
			if(y!=ban){
				if(f[x].count(y)){
					long long rec=f[x][y];
					f[x][y]=(*g[x].begin())-z,g[x].erase(g[x].find(rec)),g[x].insert(f[x][y]);
				}
				else f[x][y]=(*g[x].begin())-z,g[x].insert(f[x][y]);
			}
		}
	}
//	printf("x=%d\n",x);
//	for(map<int,long long>::iterator it=f[x].begin();it!=f[x].end();it++)
//		printf("%d %lld\n",it->first,it->second+tag[x]);
}
int main(){
	scanf("%d%d",&n,&ban);
	stk[++top]=++tot;
	for(int i=1,x,y;i<=n;i++){
		cin>>s;
		if(s=="if")
			scanf("%d",&x),tot++,v[stk[top]].push_back(make_pair(tot,x)),stk[++top]=tot;
		if(s=="set")
			scanf("%d%d",&x,&y),v[stk[top]].push_back(make_pair(-x,y));
		if(s=="end")
			top--;
	}
	f[1][0]=0,g[1].insert(0),dfs(1),ans=1e18;
	printf("%lld\n",(*g[1].begin())+tag[1]);
	return 0;
}