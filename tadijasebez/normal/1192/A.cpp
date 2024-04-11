#include <bits/stdc++.h>
using namespace std;
#define pt pair<int,int>
#define x first
#define y second
#define mp make_pair
#define pb push_back
pt operator + (pt a,pt b){return mp(a.x+b.x,a.y+b.y);}
pt operator / (pt a,int b){return mp(a.x/b,a.y/b);}
const int N=150005;
const int M=9*N;
vector<pt> pts,mv={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
vector<int> E8[M],E4[M];
int n,cmp[M],my[M],ym[N],csz,out;
pt a[N];
set<int> act;
bool huo[M];
void Consider(int x){
	if(huo[x])act.erase(my[x]);
	bool rch=0;
	for(int y:E4[x])if(cmp[y]==out)rch=1;
	bool art=0;
	assert(E8[x].size()==8);
	for(int i=0;i<8;i++){
		int y=E8[x][i];
		if(cmp[y]==-1){
			vector<int> qq;
			for(int j=(i+1)%8,las=-1,in=0;j!=i;j=(j+1)%8){
				int z=E8[x][j];
				if(las!=cmp[z])las=cmp[z],in=0;
				if(j%2==1 && !in && las!=-1)
					qq.pb(las),
					in=1;
			}
			sort(qq.begin(),qq.end());
			for(int j=1;j<qq.size();j++)
				if(qq[j]==qq[j-1])
					art=1;
			break;
		}
	}
	huo[x]=rch&&!art;
	if(huo[x])act.insert(my[x]);
}
vector<int> all[M];
void Merge(int a,int b){
	if(b==out || (a!=out && all[a].size()<all[b].size()))swap(a,b);
	for(int i:all[b])
		cmp[i]=a,
		all[a].pb(i);
	for(int i:all[b])
		for(int j:E4[i])
			if(cmp[j]==-1)
				Consider(j);
}
int ans[N];
bool was[M];
int main(){
	scanf("%i %*i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i %i",&a[i].x,&a[i].y);
		for(int dx=-1;dx<=1;dx++)
			for(int dy=-1;dy<=1;dy++)
				pts.pb(mp(a[i].x+dx,a[i].y+dy));
	}
	sort(pts.begin(),pts.end());
	pts.erase(unique(pts.begin(),pts.end()),pts.end());
	for(int i=0;i<pts.size();i++){
		for(pt d:mv){
			pt b=pts[i]+d;
			int j=lower_bound(pts.begin(),pts.end(),b)-pts.begin();
			if(j<pts.size() && pts[j]==b){
				E8[i].pb(j);
				if(d.x*d.y==0)
					E4[i].pb(j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		int j=lower_bound(pts.begin(),pts.end(),a[i])-pts.begin();
		//assert(j<pts.size() && pts[j]==a[i]);
		cmp[j]=-1;
		my[j]=i;
		ym[i]=j;
	}
	queue<int> q;
	for(int i=0;i<pts.size();i++){
		if(cmp[i]==0){
			q.push(i);
			cmp[i]=++csz;
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int v:E4[u]){
					if(cmp[v]==0){
						cmp[v]=csz;
						q.push(v);
					}
				}
			}
		}
	}
	q.push(ym[1]);
	was[ym[1]]=1;
	int num=0;
	while(q.size()){
		int u=q.front();
		num++;
		q.pop();
		for(int v:E8[u]){
			if(cmp[v]==-1 && !was[v]){
				was[v]=1;
				q.push(v);
			}
		}
	}
	if(num<n)return 0*printf("NO\n");
	out=cmp[0];
	//assert(out!=-1);
	for(int i=0;i<pts.size();i++){
		if(cmp[i]==-1)
			Consider(i);
		else
			all[cmp[i]].pb(i);
	}
	for(int pos=n;pos>=1;pos--){
		//assert(act.size());
		int x=*act.rbegin();
		act.erase(x);
		ans[pos]=x;
		x=ym[x];
		for(int y:E4[x])if(cmp[y]!=-1){cmp[x]=cmp[y];all[cmp[x]].pb(x);break;}
		//assert(cmp[x]!=-1);
		for(int y:E8[x])if(cmp[y]==-1)Consider(y);
		for(int y:E4[x])if(cmp[y]!=-1 && cmp[y]!=cmp[x])Merge(cmp[x],cmp[y]);
	}
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%i\n",ans[i]);
	return 0;
}