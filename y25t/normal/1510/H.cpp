#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define N 2005

bool _;

inline bool chkmx(int &x,int y){
	return x<y?x=y,1:0;
}

int n;
pii a[N];

pii b[N<<1];
std::stack<int> st;
std::vector<int> rt;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int sz[N],num[N][N<<1],tot,mun[N][N<<1],oto;
inline void dfs0(int u){
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs0(v);
		for(int x=sz[u]+sz[v];x<=2*sz[u]+2*sz[v];x++)
			mun[i][x]=++oto;
		sz[u]+=sz[v];
	}
	sz[u]++;
	for(int i=0;i<=2*sz[u]-1;i++)
		num[u][i]=++tot;
}

int f[N*N][2][2],g[N<<1][2][2];
struct node{
	short v,y,p,q;
	node(short v_=0,short y_=0,short p_=0,short q_=0){
		v=v_,y=y_,p=p_,q=q_;
	}
};
bool operator == (node x,node y){
	return x.v==y.v&&x.y==y.y&&x.p==y.p&&x.q==y.q;
}
std::pair<node,node> h[N*N][2][2];
node hl[N*N][2][2];
inline void dfs(int u){
	sz[u]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			f[num[u][0]][i][j]=i*a[u].sec-j*a[u].sec;
	int j=-1;
	for(int i=hd[u];i;j=i,i=e[i].nxt){
		int v=e[i].v;
		dfs(v);
		for(int x=sz[u];x<=2*sz[u]+2*sz[v];x++)
			for(int p=0;p<2;p++)
				for(int q=0;q<2;q++)
					g[x][p][q]=-inf;
		for(int x=sz[u];x<=2*sz[u];x++)
			for(int y=sz[v];y<=2*sz[v]-1;y++)
				for(int p=0;p<2;p++)
					for(int q=0;q<2;q++){
						if(chkmx(g[x+y][p][q],f[num[v][y]][p][0]+f[num[u][x]][0][q]))
							h[mun[i][x+y]][p][q]=mp(node(v,y,p,0),node(j,x,0,q));
						if(chkmx(g[x+y+1][p][q],f[num[v][y]][p][1]+f[num[u][x]][1][q]))
							h[mun[i][x+y+1]][p][q]=mp(node(v,y,p,1),node(j,x,1,q));
						if(!sz[u]&&q)
							if(chkmx(g[x+y][p][q],f[num[v][y]][p][q]))
								h[mun[i][x+y]][p][q]=mp(node(v,y,p,q),node(j,0,-1,-1));
					}
		sz[u]+=sz[v];
		for(int x=sz[u];x<=2*sz[u];x++)
			for(int p=0;p<2;p++)
				for(int q=0;q<2;q++)
					f[num[u][x]][p][q]=g[x][p][q];
	}
	for(int x=sz[u];x<=2*sz[u]+2;x++)
		for(int p=0;p<2;p++)
			for(int q=0;q<2;q++)
				g[x][p][q]=-inf;
	for(int x=sz[u];x<=2*sz[u];x++)
		for(int p=0;p<2;p++)
			for(int q=0;q<2;q++){
				if(chkmx(g[x][p][q],f[num[u][x]][0][q]+p*a[u].fir))
					hl[num[u][x]][p][q]=node(j,x,0,q);
				if(p)
					if(chkmx(g[x][p][q],f[num[u][x]][p][q]))
						hl[num[u][x]][p][q]=node(j,x,p,q);
				if(chkmx(g[x+1][p][q],f[num[u][x]][1][q]-a[u].fir+p*a[u].fir))
					hl[num[u][x+1]][p][q]=node(j,x,1,q);
			}
	sz[u]++;
	for(int x=sz[u];x<=2*sz[u]-1;x++)
		for(int p=0;p<2;p++)
			for(int q=0;q<2;q++)
				f[num[u][x]][p][q]=g[x][p][q];
}

std::vector<int> ver;
pii seg[N];
inline pii sol(int u,int x,int p,int q){
	if(sz[u]==1){
		seg[u]=mp(a[u].fir,a[u].sec);
		return mp(p?a[u].fir:-1,q?a[u].sec:-1);
	}
	ver.push_back(u);
	pii res=mp(-1,-1);
	node t=hl[num[u][x]][p][q];
	int lst=-1;
	if(p&&!t.p)
		res.fir=a[u].fir;
	else if(t.y+1==x){
		if(p)
			res.fir=a[u].fir;
		lst=a[u].fir;
	}
	while(1){
		node s=h[mun[t.v][t.y]][t.p][t.q].fir,tt=h[mun[t.v][t.y]][t.p][t.q].sec;
		auto r=sol(s.v,s.y,s.p,s.q);
		if(r.fir!=-1){
			if(p&&lst==-1){
				res.fir=r.fir;
			}
			else{
				seg[ver.back()]=mp(lst,r.fir);
				ver.pop_back();
				lst=-1;
			}
		}
		if(r.sec!=-1)
			lst=r.sec;
		if(!tt.y){
			if(tt.p==1){
				seg[ver.back()]=mp(lst,a[u].sec);
				ver.pop_back();
				lst=a[u].sec;
			}
			if(q){
				res.sec=lst;
			}
			break;
		}
		t=tt;
	}
	return res;
}

int ans;

bool __;

int main(){
//	printf("%d\n",(&_-&__)/1000/1000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].fir,&a[i].sec);
		b[i]=mp(a[i].fir,i);
		b[i+n]=mp(a[i].sec,-i);
	}
	std::sort(b+1,b+n+n+1);
	for(int i=1;i<=n+n;i++){
		if(b[i].sec<0){
			st.pop();
			if(st.size())
				addedge(st.top(),-b[i].sec);
			else
				rt.push_back(-b[i].sec);
		}
		else
			st.push(b[i].sec);
	}
	for(auto x:rt)
		dfs0(x);
	for(auto x:rt){
		dfs(x);
		ans+=f[num[x][sz[x]]][0][0];
		sol(x,sz[x],0,0);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",seg[i].fir,seg[i].sec);
}