//CF83C
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
const int N = 55;
const int M = 26;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char s[N];
string ans,t;
int n,m,k,sx,sy,tx,ty,w,e[N],a[N][N],b[N][N],d[N][N];
queue<pair<int,int> > q;
vector<pair<int,int> > v,r;
void solve(){
	int i,j,l,o,x,y,z,u;
	memset(b,0,sizeof(b));
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(e[a[i][j]])
				b[i][j]=1;
	memset(d,0,sizeof(d));
	d[tx][ty]=1;
	q.push(make_pair(tx,ty));
	while(!q.empty()){
		i=q.front().first;
		j=q.front().second;
		q.pop();
		for(o=0;o<4;o=o+1){
			x=i+dx[o];
			y=j+dy[o];
			if(!b[x][y]||d[x][y])
				continue;
			d[x][y]=d[i][j]+1;
			q.push(make_pair(x,y));
		}
	}
	if(!d[sx][sy])
		return;
	v.clear();
	
	t="";
	v.push_back(make_pair(sx,sy));
	for(z=d[sx][sy]-1;z>1;z=z-1){
		r.clear();
		u=M;
		for(l=0;l<v.size();l=l+1){
			i=v[l].first;
			j=v[l].second;
			for(o=0;o<4;o=o+1){
				x=i+dx[o];
				y=j+dy[o];
				if(d[x][y]==z){
					u=min(u,a[x][y]);
					r.push_back(make_pair(x,y));
				}
			}
		}
		t+=(u+'a');
		v.clear();
		sort(r.begin(),r.end());
		r.resize(unique(r.begin(),r.end())-r.begin());
		for(l=0;l<r.size();l=l+1){
			i=r[l].first;
			j=r[l].second;
			if(a[i][j]==u)
				v.push_back(make_pair(i,j));
		}
	}
	if(w&&ans.length()<t.length())
		return;
	if(w&&ans.length()==t.length()&&ans<=t)
		return;
	w=1;
	ans=t;
}
int main()
{
	int i,j,l,o;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%s",s+1);
		for(j=1;j<=m;j=j+1){
			if(s[j]=='S'){
				sx=i,sy=j;
				a[i][j]=M;
				continue;
			}
			if(s[j]=='T'){
				tx=i,ty=j;
				a[i][j]=M;
				continue;
			}
			a[i][j]=s[j]-'a';
		}
	}
	w=0;
	e[M]=1;
	for(i=0;i<M;i=i+1){
		e[i]=1;
		if(k==1)
			solve();
		for(j=i+1;j<M;j=j+1){
			e[j]=1;
			if(k==2)
				solve();
			for(l=j+1;l<M;l=l+1){
				e[l]=1;
				if(k==3)
					solve();
				for(o=l+1;o<M;o=o+1){
					e[o]=1;
					if(k==4)
						solve();
					e[o]=0;
				}
				e[l]=0;
			}
			e[j]=0;
		}
		e[i]=0;
	}
	if(w)
		cout<<ans;
	else
		cout<<-1;
	return 0;
}