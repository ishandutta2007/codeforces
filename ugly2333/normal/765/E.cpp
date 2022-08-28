//CF 765E
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
const int N = 222222;
int n,rt;
vector<int> v[N];
int a[N],f,ff;
set<int> S;
void dfs(int u,int fa){
	int i,s,x;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			dfs(x,u);
			if(!f)
				return;
			if(u==rt){
				S.insert(a[x]+1);
			}
			else{
				if(!a[u])
					a[u]=a[x]+1;
				else{
					if(a[u]!=a[x]+1){
						if(f==1)
							rt=u,f=0;
						else{
							cout<<-1<<endl;
							exit(0);
						}
					}
				}
			}
			if(!f)
				return;
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	rt=1;
	f=1;
	dfs(rt,0);
	memset(a,0,sizeof(a));
	S.clear();
	f=2;
	//cout<<rt<<endl;
	dfs(rt,0);
	if(S.size()>2){
		cout<<-1<<endl;
		return 0;
	}
	x=0;
	while(S.size()){
		x+=*(S.begin());
		S.erase(S.begin());
	}
	while(x%2==0){
		x/=2;
	}
	cout<<x<<endl;
	return 0;
}