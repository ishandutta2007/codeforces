#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int t,n,m,tp;
struct edge{
	int u,v;
}ed[N];
struct stak{
	int x,y,add;
}stk[N];
struct dsu{
    int fa[N<<1],len[N<<1];
    int find(int x){
        while(x!=fa[x])x=fa[x];
        return x;
    }
    void unnion(int x,int y){
        int fx=find(x),fy=find(y);
        if(len[fx]>len[fy])swap(fx,fy);
        stk[++tp]=(stak){fx,fy,len[fx]==len[fy]};
        fa[fx]=fy;
        if(len[fx]==len[fy])len[fy]++;
    }
}ty;
vector<int>gr[N];
bool pd[N],flag;
struct seg{
    vector<int>t[N<<2];
    void build(int p,int l,int r){
        t[p].resize(0);
        if(l==r)return;
        int mid=(l+r)>>1;
        build(p<<1,l,mid),build(p<<1|1,mid+1,r);
    }
    void upd(int p,int l,int r,int L,int R,int x){
        if(L>R)return;
        if(L<=l&&r<=R)return t[p].push_back(x),void();
        int mid=(l+r)>>1;
        if(L<=mid)upd(p<<1,l,mid,L,R,x);
        if(R>mid)upd(p<<1|1,mid+1,r,L,R,x);
    }
    void dfs(int p,int l,int r){
        if(flag)return;
        int ans=1,now=tp,mid=(l+r)>>1;
        for(int i:t[p]){
            int a=ty.find(ed[i].u),b=ty.find(ed[i].v);
            if(a==b){ans=0;break;}
            ty.unnion(ed[i].u,ed[i].v+n);
            ty.unnion(ed[i].v,ed[i].u+n);
        }
        if(ans){
            if(l==r)pd[l]=flag=1;
            else dfs(p<<1,l,mid),dfs(p<<1|1,mid+1,r);
        }
        while(tp>now){
            ty.len[ty.fa[stk[tp].x]]-=stk[tp].add;
            ty.fa[stk[tp].x]=stk[tp].x,tp--;
        }
    }
}tr;
int col[N],ex,ey;
void dfs(int u,int c){
	col[u]=c;
	for(auto v:gr[u]){
		if(col[v]||(u==ex&&v==ey)||(u==ey&&v==ex))continue;
		dfs(v,3-c);
	}
}
void init(){
    for(int i=1;i<=2*n;i++)ty.fa[i]=i,ty.len[i]=1;
    for(int i=1;i<=m;i++)pd[i]=0;
    for(int i=1;i<=n;i++)col[i]=0;
	tp=0,flag=0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		tr.build(1,1,m);
		for(int i=1;i<=n;i++)gr[i].resize(0);
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			gr[x].push_back(y);
            gr[y].push_back(x);
			ed[i].u=x,ed[i].v=y;
		}
		random_shuffle(ed+1,ed+m+1);
        init();
		for(int i=1;i<=m;i++)tr.upd(1,1,m,1,i-1,i),tr.upd(1,1,m,i+1,m,i);
        tr.dfs(1,1,m);
		bool chk=0;
		for(int i=1;i<=m;i++)
			if(pd[i]){
				chk=1;ex=ed[i].u,ey=ed[i].v;
				for(int o=1;o<=n;o++)if(!col[o])dfs(o,1);
                for(int o=1;o<=n;o++)col[o]--;
				if(!col[ex]&&!col[ey])for(int o=1;o<=n;o++)col[o]^=1;
				break;
			}
		if(!chk)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)putchar('0'+col[i]);
			puts("");
		}
	}
	return 0;
}