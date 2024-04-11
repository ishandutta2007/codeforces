//CF1753D
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
const int N = 633333;
const LL inf = 1e18;
int n,m,p,q;
char s[N];
int G(int i,int j){
	if(i<1||i>n||j<1||j>m)
		return -1;
	return i*m+j;
}
vector<int> v[N],h[N];
LL d[N];
int b[N],e[N];
priority_queue<pair<LL,int> > Q;
void ade(int x,int y,int z){
	if(x==-1||y==-1)
		return;
	//v[x].push_back(y);
	//h[x].push_back(z);
	v[y].push_back(x);
	h[y].push_back(z);
}
int main()
{
	int i,j,x,y;
	LL z;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(i=1;i<=n;i++){
		scanf("%s",s+1);
		for(j=1;j<=m;j++){
			if(s[j]=='.')
				d[G(i,j)]=0,Q.push(make_pair(-0,G(i,j)));
			else
				d[G(i,j)]=inf;
			if(s[j]=='#')
				b[G(i,j)]=1;
			if(s[j]=='L'){
				ade(G(i,j+1),G(i,j-1),q),ade(G(i,j+1),G(i-1,j),p),ade(G(i,j+1),G(i+1,j),p);
				ade(G(i,j),G(i,j+2),q),ade(G(i,j),G(i-1,j+1),p),ade(G(i,j),G(i+1,j+1),p);
			}
			if(s[j]=='U'){
				ade(G(i+1,j),G(i-1,j),q),ade(G(i+1,j),G(i,j-1),p),ade(G(i+1,j),G(i,j+1),p);
				ade(G(i,j),G(i+2,j),q),ade(G(i,j),G(i+1,j-1),p),ade(G(i,j),G(i+1,j+1),p);
			}
		}
	}
	while(!Q.empty()){
		x=Q.top().second;
		Q.pop();
		if(e[x])
			continue;
		e[x]=1;
		for(i=0;i<v[x].size();i++){
			y=v[x][i];
			z=d[x]+h[x][i];
			if(!b[y]&&d[y]>z){
				d[y]=z;
				Q.push(make_pair(-z,y));
			}
		}
	}
	z=inf;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(i+1<=n)
				z=min(z,d[G(i,j)]+d[G(i+1,j)]);
			if(j+1<=m)
				z=min(z,d[G(i,j)]+d[G(i,j+1)]);
		}
	if(z>=inf)
		z=-1;
	printf("%lld\n",z);
	return 0;
}