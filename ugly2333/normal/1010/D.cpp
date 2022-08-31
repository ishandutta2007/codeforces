//CF1010D
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
const int N = 1e6+16;
char ch[11];
int n,a[N],l[N],r[N],b[N],c[N];
void dfs1(int u){
	if(a[u]&&l[u])
		dfs1(l[u]);
	if(a[u]&&r[u])
		dfs1(r[u]);
	if(a[u]==0)
		b[u]=l[u];
	if(a[u]==1)
		b[u]=b[l[u]]^1;
	if(a[u]==2)
		b[u]=b[l[u]]&b[r[u]];
	if(a[u]==3)
		b[u]=b[l[u]]|b[r[u]];
	if(a[u]==4)
		b[u]=b[l[u]]^b[r[u]];
}
void dfs2(int u){
	if(a[u]==0)
		c[u]=1;
	if(a[u]==1)
		dfs2(l[u]);
	if(a[u]==2){
		if(b[l[u]])
			dfs2(r[u]);
		if(b[r[u]])
			dfs2(l[u]);
	}
	if(a[u]==3){
		if(!b[l[u]])
			dfs2(r[u]);
		if(!b[r[u]])
			dfs2(l[u]);
	}
	if(a[u]==4){
		dfs2(r[u]);
		dfs2(l[u]);
	}
}
int main()
{
	int i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%s%d",ch,l+i);
		if(ch[0]=='I'||ch[0]=='N'){
			if(ch[0]=='N')
				a[i]=1;
		}
		else{
			scanf("%d",r+i);
			if(ch[0]=='A')
				a[i]=2;
			if(ch[0]=='O')
				a[i]=3;
			if(ch[0]=='X')
				a[i]=4;
		}
	}
	dfs1(1);
	dfs2(1);
	for(i=1;i<=n;i=i+1)
		if(!a[i])
			cout<<(b[1]^c[i]);
	return 0;
}