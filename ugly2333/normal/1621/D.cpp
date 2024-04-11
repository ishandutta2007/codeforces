//CF1621D
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
const int N = 555;
const LL inf = 1e18;
int n,a[N][N];
LL d[N*N];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
priority_queue<pair<LL,int> > Q;
int G(int i,int j){
	return i*N+j;
}
void go(int z,LL w){
	if(d[z]>w){
		d[z]=w;
		Q.push(make_pair(-w,z));
	}
}
LL solve(int sx,int sy){
	int i,j,x,y,z,xx,yy;
	LL w;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			d[G(i,j)]=inf;
	for(i=0;i<n;i+=max(1,n-1)){
		go(G(i,0),a[sx+i][sy]);
		go(G(i,n-1),a[sx+i][sy+n-1]);
	}
	while(!Q.empty()){
		w=-Q.top().first;
		j=Q.top().second;
		Q.pop();
		if(d[j]<w)
			continue;
		x=j/N,y=j%N;
		for(i=0;i<4;i++){
			xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<n&&yy>=0&&yy<n)
				go(G(xx,yy),w+a[sx+xx][sy+yy]);
		}
	}
	w=inf;
	for(i=0;i<n;i+=max(1,n-1))
		w=min(w,d[G(0,i)]),w=min(w,d[G(n-1,i)]);
	return w;
}
int main()
{
	int T,i,j;
	LL s;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=0;i<n*2;i++)
			for(j=0;j<n*2;j++)
				scanf("%d",a[i]+j);
		s=min(solve(n,0),solve(0,n));
		for(i=n;i<n*2;i++)
			for(j=n;j<n*2;j++)
				s+=a[i][j];
		printf("%lld\n",s);
	}
	return 0;
}