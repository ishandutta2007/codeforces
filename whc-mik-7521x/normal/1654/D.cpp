#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353;
int t,n,kot[N];
set<int>st;
struct node{
    int x,tim;
};
struct edge{
    int to,nex;
    vector<node>w1,w2;
};
edge ed[N<<1];
int cnt,h[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
long long inv(long long x){
    return fp(x,mod-2);
}
void add(int st,int et,vector<node>w1,vector<node>w2){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w1=w1;
    ed[cnt].w2=w2;
    ed[cnt].nex=h[st];
    h[st]=cnt;
}
vector<long long>pri;
long long divi[N];
void solve_prime(long long mx){
    divi[1]=1;
    for(long long i=2;i<=mx;i++){
        if(!divi[i])pri.push_back(i),divi[i]=i;
        for(long long o:pri){
            if(o>divi[i]||o*i>mx)break;
            divi[i*o]=o;
        }
    }
}
vector<node>calc(int x){
    vector<node>res;
    for(int i:pri){
        if(i*i>x)break;
        if(x%i==0){
            st.insert(i);
            int ct=0;
            while(x%i==0)x/=i,ct++;
            res.push_back({i,ct});
        }
    }
    if(x!=1)res.push_back({x,1}),st.insert(x);
    return res;
}
void dec(vector<node>kk){
    for(auto it:kk){
        kot[it.x]=max(0,kot[it.x]-it.tim);
    }
}
void inc(vector<node>kk){
    for(auto it:kk){
        kot[it.x]=kot[it.x]+it.tim;
    }
}
void dfs(int x,int fa){
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        dec(ed[i].w1);
        inc(ed[i].w2);
        dfs(v,x);
        dec(ed[i].w2);
        inc(ed[i].w1);
    }
}
long long ans=0,now;
void init(){
    ans=0;
    now=1;
    for(auto it:st)now=now*fp(it,kot[it])%mod;
}
void decc(vector<node>kk){
    for(auto it:kk){
        now=now*inv(fp(it.x,it.tim))%mod;
    }
}
void incc(vector<node>kk){
    for(auto it:kk){
        now=now*fp(it.x,it.tim)%mod;
    }
}
void getans(int x,int fa){
    ans=(ans+now)%mod;
    for(int i=h[x];i;i=ed[i].nex){
        int v=ed[i].to;
        if(v==fa)continue;
        decc(ed[i].w1);
        incc(ed[i].w2);
        getans(v,x);
        decc(ed[i].w2);
        incc(ed[i].w1);
    }
}
void cle(){
    for(auto it:st)kot[it]=0;
    st.clear();
    for(int i=1;i<=n;i++)h[i]=0;
    cnt=0;
}
int main(){
    solve_prime(2e5);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cle();
        for(int i=1;i<n;i++){
            int x,y,k1,k2;
            scanf("%d%d%d%d",&x,&y,&k1,&k2);
            int d=__gcd(k1,k2);
            vector<node>s1=calc(k1/d),s2=calc(k2/d);
            add(x,y,s1,s2);
            add(y,x,s2,s1);
        }
        dfs(1,0);
        init();
        getans(1,0);
        printf("%lld\n",ans);
    }
    return  0;
}