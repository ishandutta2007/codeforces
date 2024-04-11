//CF 997B
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
int n,b[N],c[N];
void dfs(int u,int k){
	if(u>=N||k>n||b[u])
		return;
	b[u]=1;
	dfs(u+49,k+1);
	dfs(u+45,k+1);
	dfs(u+40,k+1);
}
void dfs2(int u,int k){
	if(u>=N||k>n||c[u])
		return;
	c[u]=1;
	dfs2(u+49,k+1);
	dfs2(u+9,k+1);
	dfs2(u+4,k+1);
}
int main()
{
	int i,l;
	LL s,t;
	cin>>n;
	s=(LL)n*50;
	if(s<=(LL)N-100){
		dfs2(n,0);
		t=0;
		for(i=1;(LL)i<=s;i=i+1)
			t+=c[i];
		cout<<t;
		return 0;
	}
	dfs2(0,0);
	dfs(0,0);
	t=0;
	for(i=1;i<N-1000;i=i+1)
		t+=1-b[i]+1-c[i];
	cout<<s-n+1-t;
	return 0;
}