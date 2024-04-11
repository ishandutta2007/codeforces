//CF715B
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
const LL inf = 1e15;
LL ab(LL x){
	if(x<0)
		return -x;
	return x;
}
int n,m,s,t,a[N][N],f[N],w[N];
LL l,b[N][N],d[N];
priority_queue<pair<LL,int> > q;
void dijk(int s){
	int i,x,y;
	LL o;
	for(i=0;i<n;i=i+1)
		d[i]=inf,f[i]=-1;
	q.push(make_pair(0,s));
	d[s]=0;
	while(!q.empty()){
		x=q.top().second;
		o=-q.top().first;
		q.pop();
		if(o!=d[x])
			continue;
		for(y=0;y<n;y=y+1){
			if(!a[x][y])
				continue;
			o=d[x]+ab(b[x][y]);
			if(d[y]>o){
				q.push(make_pair(-o,y));
				d[y]=o;
				f[y]=x;
			}
		}
	}
}
void ch(LL x,LL y){
	int i,j;
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1)
			if(a[i][j]&&b[i][j]==x)
				b[i][j]=y;
}
int main()
{
	int i,x,y,z;
	LL o;
	cin>>n>>m>>l>>s>>t;
	while(m--){
		cin>>x>>y>>z;
		if(!z)
			z=-1;
		a[x][y]=1,b[x][y]=z;
		a[y][x]=1,b[y][x]=z;
	}
	ch(-1,inf);
	dijk(s);
	if(d[t]<l){
		cout<<"NO";
		return 0;
	}
	ch(inf,-1);
	dijk(s);
	if(d[t]>l){
		cout<<"NO";
		return 0;
	}
	m=0;
	for(x=t;x!=s;x=f[x])
		w[m++]=x;
	w[m]=s;
	ch(-1,inf);
	for(i=1;i<=m;i=i+1)
		if(b[w[i]][w[i-1]]==inf)
			b[w[i]][w[i-1]]=-1,b[w[i-1]][w[i]]=-1;
	for(i=1;i<=m;i=i+1){
		if(b[w[i]][w[i-1]]!=-1)
			continue;
		dijk(t);
		o=l-d[w[i-1]];
		if(d[s]==l)
			break;
		dijk(s);
		o-=d[w[i]];
		b[w[i]][w[i-1]]=o,b[w[i-1]][w[i]]=o;
	}
	cout<<"YES"<<endl;
	for(x=0;x<n;x=x+1)
		for(y=x;y<n;y=y+1)
			if(a[x][y])
				cout<<x<<' '<<y<<' '<<ab(b[x][y])<<endl;
	return 0;
}