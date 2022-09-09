//	2100
#include <bits/stdc++.h>
using namespace std;
#define pt pair<int,int>
#define x first
#define y second
#define ldb double
#define ll long long
#define pb push_back
const int N=100050;
int go[N][4],nxt[N],xl,yl,xr,yr,n,tsz,esz=1,my[N],csz,sec[N];
map<pair<int,int>,int> edx;
pt pts[N];
bool was[N];
vector<int> ply[N];
ldb area[N];
ll cross(pt a,pt b){return (ll)a.x*b.y-(ll)a.y*b.x;}
ldb Area(vector<int> p){
	ldb ans=0;
	for(int i=0,j=(int)p.size()-1;i<p.size();j=i,i++){
		ans+=cross(pts[p[i]],pts[p[j]]);
	}
	return abs(ans)/2;
}
void Connect(int u,int v){
	edx[{u,v}]=++esz;sec[esz]=v;
	edx[{v,u}]=++esz;sec[esz]=u;
	if(pts[u].x==pts[v].x){
		if(pts[u].y>pts[v].y)swap(u,v);
		go[v][0]=u;
		go[u][2]=v;
	}else{
		if(pts[u].x>pts[v].x)swap(u,v);
		go[v][1]=u;
		go[u][3]=v;
	}
}
void Build(int u){
	for(int i=0;i<4;i++)if(go[u][i]){
		for(int j=1;j<=4;j++)if(go[u][(i+j)%4]){
			nxt[edx[{go[u][i],u}]]=edx[{u,go[u][(i+j)%4]}];
			break;
		}
	}
}
vector<int> side[4],E[N];
void AddEdge(int u,int v){E[u].pb(v);E[v].pb(u);}
ldb sum[2];
bool vis[N];
int ty[N];
void DFS(int u,int t=0){
	vis[u]=1;
	sum[t]+=area[u];
	ty[u]=t;
	for(int v:E[u])if(!vis[v])DFS(v,t^1);
}
bool CuttingRayTest(ldb x,ldb y){
	int cnt=0;
	for(int i=1,j=n;i<=n;j=i,i++){
		if(pts[i].x==pts[j].x&&pts[i].x>x){
			int mx=max(pts[i].y,pts[j].y);
			int mn=min(pts[i].y,pts[j].y);
			if(mn<y&&mx>y)cnt++;
		}
	}
	return cnt%2;
}
int main(){
	scanf("%i %i %i %i",&xl,&yr,&xr,&yl);
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i %i",&pts[i].x,&pts[i].y);
	}
	tsz=n;
	pts[++tsz]={xl,yl};
	pts[++tsz]={xr,yl};
	pts[++tsz]={xr,yr};
	pts[++tsz]={xl,yr};
	side[0]={n+1,n+2};
	side[1]={n+2,n+3};
	side[2]={n+3,n+4};
	side[3]={n+4,n+1};
	for(int i=1,j=n;i<=n;j=i,i++){
		if(pts[i].x==pts[j].x){
			int mn=min(pts[i].y,pts[j].y);
			int mx=max(pts[i].y,pts[j].y);
			if(xl<pts[i].x&&pts[i].x<xr&&mx>yl&&mn<yr){
				if(mn<=yl&&mx>=yr){
					pts[++tsz]={pts[i].x,yl};side[0].pb(tsz);
					pts[++tsz]={pts[i].x,yr};side[2].pb(tsz);
					Connect(tsz-1,tsz);
				}else if(mn<=yl){
					pts[++tsz]={pts[i].x,yl};side[0].pb(tsz);
					Connect(tsz,pts[i].y==mx?i:j);
				}else if(mx>=yr){
					pts[++tsz]={pts[i].x,yr};side[2].pb(tsz);
					Connect(tsz,pts[i].y==mn?i:j);
				}else Connect(i,j);
			}
		}else{
			int mn=min(pts[i].x,pts[j].x);
			int mx=max(pts[i].x,pts[j].x);
			if(yl<pts[i].y&&pts[i].y<yr&&mx>xl&&mn<xr){
				if(mn<=xl&&mx>=xr){
					pts[++tsz]={xl,pts[i].y};side[3].pb(tsz);
					pts[++tsz]={xr,pts[i].y};side[1].pb(tsz);
					Connect(tsz-1,tsz);
				}else if(mn<=xl){
					pts[++tsz]={xl,pts[i].y};side[3].pb(tsz);
					Connect(tsz,pts[i].x==mx?i:j);
				}else if(mx>=xr){
					pts[++tsz]={xr,pts[i].y};side[1].pb(tsz);
					Connect(tsz,pts[i].x==mn?i:j);
				}else Connect(i,j);
			}
		}
	}
	for(int s=0;s<4;s++){
		sort(side[s].begin(),side[s].end(),[&](int i,int j){return pts[i]<pts[j];});
		for(int i=1;i<side[s].size();i++)Connect(side[s][i-1],side[s][i]);
	}
	for(int i=1;i<=tsz;i++)Build(i);
	for(int i=2;i<=esz;i++)if(!was[i]){
		csz++;int j=i;
		while(!was[j]){
			was[j]=1;
			my[j]=csz;
			ply[csz].pb(sec[j]);
			j=nxt[j];
		}
		//area[csz]=Area(ply[csz]);
		area[csz]=1;
	}
	int ban=my[edx[{side[0][1],side[0][0]}]];
	for(int i=2;i<=esz;i+=2){
		if(my[i]!=ban&&my[i+1]!=ban){
			AddEdge(my[i],my[i+1]);
		}
	}
	DFS(1==ban?2:1);
	int xr=1;
	if(CuttingRayTest(xl+0.5,yl+0.5))xr=0;
	ldb ans=sum[ty[my[edx[{side[0][0],side[0][1]}]]]^xr];
	printf("%.0f",ans);
	return 0;
}