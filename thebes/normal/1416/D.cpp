#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 5e5+5, MM = 3e5+5, MQ = 5e5+5, LG = 20;
int N, M, Q, i, j, x, y, w, ncnt, arr[MN], ds[MN], vs[MN], vis[MN][2], dep[MN], anc[LG][MN], sp[LG][MN], rem[MM], nxt;
vector<pii> adj[MN]; pii ed[MM], q[MQ], st[3*MN];
int fnd(int x){return ds[x]=ds[x]==x?x:fnd(ds[x]);}

void dfs(int n,int p,int d){
	dep[n] = d;
	anc[0][n] = p;
	vis[n][0] = ++nxt;
	vs[n] = 1;
	for(auto v : adj[n]){
		if(v.F==p){
			sp[0][n]=v.S;
			continue;
		}
		dfs(v.F, n, d+1);
	}
	vis[n][1] = nxt;
}

void upd(int i,int s,int e,int idx,int val){
	if(s^e){
		if((s+e)/2<idx) upd(2*i+1,(s+e)/2+1,e,idx,val);
		else upd(2*i,s,(s+e)/2,idx,val);
		st[i].F = max(st[2*i].F,st[2*i+1].F);
		st[i].S = (st[2*i].F>st[2*i+1].F)?st[2*i].S:st[2*i+1].S;
	}
	else st[i] = {val, s};
}

pii qu(int i,int s,int e,int ss,int se){
	if(s>=ss&&e<=se) return st[i];
	else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
	else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
	else{
		pii l = qu(2*i,s,(s+e)/2,ss,se), r = qu(2*i+1,(s+e)/2+1,e,ss,se);
		return make_pair(max(l.F,r.F),(l.F>r.F)?l.S:r.S);
	}
}

int up(int n,int lim){
	for(int i=LG-1;i>=0;i--){
		if(sp[i][n]>=lim){
			n = anc[i][n];
		}
	}
	return n;
}

int main(){
	scanf("%d%d%d",&N,&M,&Q);
	ncnt = N;
	for(i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	for(i=1;i<=N+M;i++)
        ds[i] = i;
	for(i=1;i<=M;i++){
		scanf("%d%d",&x,&y);
		ed[i] = {x,y};
	}
	for(i=1;i<=Q;i++){
		scanf("%d%d",&x,&y);
		q[i] = {x,y};
		if(x==2) rem[y] = 1;
	}
	for(i=1;i<=M;i++){
		if(!rem[i]){
			if(fnd(ed[i].F)^fnd(ed[i].S)){
				ds[fnd(ed[i].F)]=fnd(ed[i].S);
				adj[ed[i].F].pb({ed[i].S,Q+1});
				adj[ed[i].S].pb({ed[i].F,Q+1});
			}
		}
	}
	for(i=Q;i>=1;i--){
		if(q[i].F==2){
			x = ed[q[i].S].F, y = ed[q[i].S].S;
			if(fnd(x)^fnd(y)){
			    x = fnd(x), y = fnd(y);
                ds[x] = ds[y] = ++ncnt;
                adj[ncnt].pb({x,i});
                adj[ncnt].pb({y,i});
                adj[x].pb({ncnt,i});
                adj[y].pb({ncnt,i});
			}
		}
	}
	for(i=1;i<=ncnt;i++){
        if(fnd(i)^i) continue;
		dfs(i, 0, 0);
	}
	for(j=1;j<LG;j++){
		for(i=1;i<=ncnt;i++){
			anc[j][i] = anc[j-1][anc[j-1][i]];
			sp[j][i] = min(sp[j-1][i],sp[j-1][anc[j-1][i]]);
		}
	}
	for(i=1;i<=N;i++){
		upd(1,1,ncnt,vis[i][0],arr[i]);
	}
	for(i=1;i<=Q;i++){
		if(q[i].F==1){
			x = q[i].S;
			x = up(x, i);
			if(x==q[i].S){
                if(adj[x].empty()){
                    pii res = qu(1,1,ncnt,vis[x][0],vis[x][0]);
                    printf("%d\n",res.F);
                    upd(1,1,ncnt,res.S,0);
                }
                else{
                    int lo = 0, hi = (int)adj[x].size();
                    while(lo<hi){
                        int mid = (lo+hi)>>1;
                        if(adj[x][mid].S>=i) lo=mid+1;
                        else hi=mid;
                    }
                    lo--;
                    if(lo>=0){
                        pii res = qu(1,1,ncnt,vis[x][0],vis[adj[x][lo].F][1]);
                        printf("%d\n",res.F);
                        upd(1,1,ncnt,res.S,0);
                    }
                    else{
                        pii res = qu(1,1,ncnt,vis[x][0],vis[x][0]);
                        printf("%d\n",res.F);
                        upd(1,1,ncnt,res.S,0);
                    }
                }
			}
			else{
                pii res = qu(1,1,ncnt,vis[x][0],vis[x][1]);
                printf("%d\n",res.F);
                upd(1,1,ncnt,res.S,0);
			}
		}
	}
	return 0;
}