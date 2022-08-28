//CF1188A2
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
const int N = 1111;
int n,a[N],e1,e2;
vector<int> v[N],h[N],ans[3];
void dfs(int u,int fa){
	int i,x;
	if(v[u].size()==1){
		if(!e1)
			e1=u;
		e2=u;
	}
	for(i=0;i<v[u].size();i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
	}
}
void go(int x,int y,int z){
	if(x==y||!z)
		return;
	ans[0].push_back(x);
	ans[1].push_back(y);
	ans[2].push_back(z);
}
int main()
{
	int i,x,y,z,a1,a2,b1,b2;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		a[x]++,a[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
		h[x].push_back(z);
		h[y].push_back(z);
	}
	x=1;
	for(i=1;i<=n;i=i+1)
		if(a[i]==2){
			cout<<"NO\n";
			x=0;
			break;
		}
	if(x)
		cout<<"YES\n";
	else
		return 0;
	for(i=1;i<=n;i=i+1){
		for(x=0;x<v[i].size();x=x+1){
			y=v[i][x];
			if(i>y)
				continue;
			z=h[i][x]/2;
			e1=0,e2=0;
			dfs(i,y);
			a1=e1,a2=e2;
			e1=0,e2=0;
			dfs(y,i);
			b1=e1,b2=e2;
			go(a1,b1,z);
			go(a2,b2,z);
			go(a1,a2,-z);
			go(b1,b2,-z);
		}
	}
	cout<<ans[0].size()<<endl;
	for(i=0;i<ans[0].size();i=i+1)
		cout<<ans[0][i]<<' '<<ans[1][i]<<' '<<ans[2][i]<<endl;
	return 0;
}