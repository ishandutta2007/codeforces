#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e5+10;

int n,m,len,b[N],L[N],R[N],fLCP[N][20],pos[N],S[N],SA[N],LCP[N],Tkey[N],Pkey[N],Spos[N],ans[N];
char ts[N];
vector <int> q[N],queF[N],que[N];
void add(int x,int v){
    x++;
    while (x<=len){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    x++;
    int tmp=0;
    while (x){
        tmp+=b[x];
        x-=x&-x;
    }
    return tmp;
}
int RMQ(int x,int y){
    int bar=int(log2(y-x+1));
    return min(fLCP[x][bar],fLCP[y-(1<<bar)+1][bar]);
}
void prepare(){
    scanf("%d%d",&n,&m);
    len=0;
    FOR(i,1,n){
        scanf("\n%s",ts);
        int m1=strlen(ts);
        pos[i]=len;
        REP(i,0,m1) S[len++]=ts[i]-'a'+n;
        S[len++]=n-i;
    }
    pos[n+1]=len;
    FOR(i,1,m){
        int x;
        scanf("%d%d%d",L+i,R+i,&x);
        que[x].push_back(i);
    }
}
int comp(int x,int y,int t){
    if (Tkey[x]==Tkey[y]) return Tkey[(x+(1<<t))%len]!=Tkey[(y+(1<<t))%len];
    return 1;
}
void buildSA_LCP(){
    ///init
    int top=0;
    REP(i,0,len) q[S[i]].push_back(i);
    REP(i,0,n+26)
        while (!q[i].empty()) SA[top++]=q[i].back(),q[i].pop_back();
    REP(i,1,len) Pkey[SA[i]]=Pkey[SA[i-1]]+(S[SA[i]]!=S[SA[i-1]]);
    ///
    for(int t=0;Pkey[SA[len-1]]<len-1;t++){
        //REP(i,0,len) printf("%d ",S[i]);ENDL;
//        REP(i,0,len) printf("%d ",SA[i]);ENDL;
//        REP(i,0,len) printf("%d ",Pkey[i]);ENDL;
        REP(i,0,len) Tkey[SA[i]]=Pkey[SA[i]];
        FORD(i,len-1,0){
            int pos=(SA[i]-(1<<t)+len)%len;
            q[Pkey[pos]].push_back(pos);
        }
        top=0;
        FOR(i,0,Tkey[SA[len-1]])
            while (!q[i].empty()) SA[top++]=q[i].back(),q[i].pop_back();
        REP(i,1,len) Pkey[SA[i]]=Pkey[SA[i-1]]+comp(SA[i],SA[i-1],t);
    }
    ///LCP
    REP(i,0,len) Spos[SA[i]]=i;
    top=0;
    REP(i,0,len){
        top=max(top-1,0);
        int x=SA[Spos[i]-1];
        while (S[x+top]==S[i+top]) top++;
        LCP[Spos[i]]=top;
    }
    ///sparse table
    REP(i,0,len) fLCP[i][0]=LCP[i];
    FOR(j,1,int(log2(len)))
        FOR(i,0,len-(1<<j)) fLCP[i][j]=min(fLCP[i][j-1],fLCP[i+(1<<(j-1))][j-1]);
}
ii find_pos(int x){
    int cpos=Spos[pos[x]];
    //printf("%d %d\n",x,cpos);
    int cL=1,cR=cpos,clen=pos[x+1]-pos[x]-1;
    while (cL<=cR){
        int cM=(cL+cR)/2;
        if (RMQ(cM,cpos)<clen) cL=cM+1;
        else cR=cM-1;
    }
    int tmp=cR;
    cL=cpos+1,cR=len-1;
    while (cL<=cR){
        int cM=(cL+cR)/2;
        if (RMQ(cpos+1,cM)<clen) cR=cM-1;
        else cL=cM+1;
    }
    return ii(tmp,cR);
}
void solve(){
    buildSA_LCP();
//    REP(i,0,len) printf("%d ",S[i]);ENDL;
//    REP(i,0,len) printf("%d ",SA[i]);ENDL;
//    REP(i,0,len) printf("%d ",LCP[i]);ENDL;
    ///find query
    FOR(i,1,n){
        ii cur=find_pos(i);
//        printf("%d %d %d\n",i,cur.X,cur.Y);
        for(auto j:que[i]){
            queF[cur.X-1].push_back(-j);
            queF[cur.Y].push_back(j);
        }
    }
    ///go from 0 to len-1
    REP(i,0,len){
        add(SA[i],1);
        for(auto j:queF[i]){
            int sign=(j<0)?-1:1,idx=sign*j;
            ans[idx]+=sign*get(pos[R[idx]+1]-1);
            ans[idx]-=sign*get(pos[L[idx]]-1);
        }
    }
    //FOR(i,1,m) printf("%d %d\n",pos[L[i]]-1,pos[R[i]+1]-1);
    FOR(i,1,m) printf("%d\n",ans[i]);
}
int main(){
    prepare();
    solve();
}