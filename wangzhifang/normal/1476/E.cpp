#include <map>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define max_n 100000
int d[max_n+1],q[max_n+1],k,flg;
map<string,int>mp;
char st[max_n+1];
string a[max_n+1];
vector<int> g[max_n+1];
void dfs(int x,int i,string r,int p){	
	if(i==k){
		if(!mp.count(r))
			return;
		int id=mp[r];
		if(id!=p)
			g[p].push_back(id),d[id]++;
		else
			flg=1;
		return;
	}
	dfs(x,i+1,r+a[x][i],p);
	dfs(x,i+1,r+"_",p);
}
int main(){
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; ++i){
		scanf("%s",st);
		a[0]=st;
		mp[a[0]]=i;
	}
	for(int i=1; i<=m; ++i){
		scanf("%s",st);
		a[i]=st;
		int p;
		scanf("%d",&p);
		flg=0;
		dfs(i,0,"",p);
		if(!flg){
			puts("NO");
			return 0;
		}
	}
	int e=0;
	for(int i=1; i<=n; ++i)
		if(!d[i])
			q[e++]=i;
	int b=0;
	while(b<e){
		int u=q[b++];
		for(auto v:g[u]){
			d[v]--;
			if(!d[v])
				q[e++]=v;
		}
	}
	if(e!=n)
		puts("NO");
	else{
		puts("YES");
		for(int i=0; i<e; ++i)
			printf("%d ",q[i]);
	}
	return 0;
}