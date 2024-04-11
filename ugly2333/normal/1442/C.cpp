//CF1442C
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
const int N = 222222;
const int K = 22;
const int MO = 998244353;
int n,m,ans,w[N][K][2];
vector<int> v[N],r[N];
struct node{
	int x,y,z;
	node(int X=0,int Y=0,int Z=0){
		x=X,y=Y,z=Z;
	}
}z,p,an;
bool operator<(node p,node q){
	if(p.x!=q.x)
		return p.x>q.x;
	return p.y>q.y;
}
priority_queue<node> Q;
int main()
{
	int i,j,x,y,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		r[y].push_back(x);
	}
	Q.push(node(0,-1,1));
	an=node(N,N,N);
	ans=MO;
	while(!Q.empty()){
		z=Q.top();
		Q.pop();
		x=z.z;
		if(x==n){
			if(z.x<=25)
				ans=min(ans,(1<<z.x)+z.y);
			else
				if(an<z)
					an=z;
		}
		if(w[x][min(20,z.x)][z.x&1])
			continue;
		w[x][min(20,z.x)][z.x&1]=1;
		p=z;
		if(p.x&1)
			p.x++;
		p.y++;
		for(i=v[x].size();i--;){
			y=v[x][i];
			p.z=y;
			Q.push(p);
		}
		p=z;
		if(!(p.x&1))
			p.x++;
		p.y++;
		for(i=r[x].size();i--;){
			y=r[x][i];
			p.z=y;
			Q.push(p);
		}
	}
	if(ans<MO){
		printf("%d",ans);
		return 0;
	}
	x=1;
	for(i=0;i<an.x;i=i+1)
		x=(x+x)%MO;
	printf("%d",(an.y+x)%MO);
	return 0;
}