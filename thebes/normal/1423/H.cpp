#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5, MM = 5e5+5;
int N, Q, K, i, j, x, y, w, d[MM], ds[MN], sz[MN], rnk[MN];
struct qur{int t, x, y;}q[MM];
vector<pii> st[3*MM];
struct evt{int x, y, rnk;};
stack<evt> stk;

int fnd(int x){return ds[x]==x?x:fnd(ds[x]);}

void upd(int i,int s,int e,int ss,int se,pii val){
    if(s>=ss&&e<=se) st[i].pb(val);
    else if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val);
    else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val);
    else upd(2*i,s,(s+e)/2,ss,se,val), upd(2*i+1,(s+e)/2+1,e,ss,se,val);
}

void solve(int i,int s,int e){
    int ecnt = 0;
    for(auto v : st[i]){
        x = v.F, y = v.S;
        if(fnd(x)^fnd(y)){
            x = fnd(x), y = fnd(y);
            if(rnk[x]<rnk[y]) swap(x,y);
            int c = (rnk[x]==rnk[y])?1:0;
            stk.push({x,y,c});
            rnk[x] += c;
            sz[x] += sz[y];
            ds[y] = x;
            ecnt++;
        }
    }
    if(s^e){
        solve(2*i,s,(s+e)/2);
        solve(2*i+1,(s+e)/2+1,e);
    }
    else if(q[s].t==2){
        printf("%d\n",sz[fnd(q[s].x)]);
    }
    while(ecnt--){
        auto hm = stk.top(); stk.pop();
        x = hm.x, y = hm.y, w = hm.rnk;
        rnk[x] -= w;
        sz[x] -= sz[y];
        ds[y] = y;
    }
}

int main(){
    scanf("%d%d%d",&N,&Q,&K);
    for(i=1;i<=Q;i++){
        scanf("%d",&q[i].t);
        d[i] = d[i-1];
        if(q[i].t==1) scanf("%d%d",&q[i].x,&q[i].y);
        else if(q[i].t==2) scanf("%d",&q[i].x);
        else d[i]++;
    }
    for(i=1;i<=Q;i++){
        if(q[i].t==1){
            int idx = lower_bound(d+1,d+Q+1,d[i]+K)-d;
            upd(1,1,Q,i,min(Q,idx),make_pair(q[i].x,q[i].y));
        }
    }
    for(i=1;i<=N;i++){
        ds[i] = i;
        sz[i] = 1;
    }
    solve(1,1,Q);
    return 0;
}