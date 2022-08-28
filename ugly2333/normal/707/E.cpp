//CF707E
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
const int N = 2222;
int n,m,k,s[N],a[N][N],u,r[N*N],p[N];
int w,lx[N],rx[N],ly[N],ry[N];
vector<int> v[N][N],q[N];
LL b[N][N],t[N];
void ad(int x,LL y){
	if(!x)
		return;
	while(x<=m){
		t[x]+=y;
		x+=x&-x;
	}
}
LL qu(int x){
	LL y=0;
	while(x){
		y+=t[x];
		x-=x&-x;
	}
	return y;
}
int main()
{
	char ch[11];
	int i,j,x,y,z;
	LL e;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i=i+1){
		scanf("%d",s+i);
		for(j=0;j<s[i];j=j+1){
			scanf("%d%d%d",&x,&y,&z);
			a[x][y]=z;
			v[i][x].push_back(y);
		}
	}
	scanf("%d",&u);
	for(i=1;i<=u;i=i+1){
		scanf("%s",ch);
		if(ch[0]=='S')
			scanf("%d",r+i);
		else{
			w++;
			r[i]=-w;
			scanf("%d%d%d%d",lx+w,ly+w,rx+w,ry+w);
			q[lx[w]-1].push_back(-w);
			q[rx[w]].push_back(w);
		}
	}
	for(i=1;i<=k;i=i+1){
		memset(t,0,sizeof(t));
		for(j=0;j<=n;j=j+1){
			for(x=v[i][j].size();x--;)
				y=v[i][j][x],ad(y,a[j][y]);
			for(x=q[j].size();x--;){
				y=q[j][x];
				if(y>0)
					b[i][y]+=qu(ry[y])-qu(ly[y]-1);
				else
					b[i][-y]-=qu(ry[-y])-qu(ly[-y]-1);
			}
		}
	}
	for(i=1;i<=k;i=i+1)
		p[i]=1;
	for(i=1;i<=u;i=i+1){
		if(r[i]>0){
			p[r[i]]^=1;
			continue;
		}
		j=-r[i];
		e=0;
		for(x=1;x<=k;x=x+1)
			if(p[x])
				e+=b[x][j];
		cout<<e<<endl;
	}
	return 0;
}