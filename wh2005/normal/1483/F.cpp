#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+9;
int n,head[N],tot,tag[N],tp[N];
string s[N];
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}

namespace ACAM{
    #define tr(u,c) t[u].ch[c]
    #define fl(u) t[u].fail
    int tot;
    struct ACAM{
        int ch[26],fail;
        ACAM(){memset(ch,0,sizeof(ch));fail=0;}
    }t[N];
    void begin(){tot=0;return ;}
    void add(string a){
        int u=0,d=0;
        for(int i=0;i<a.length();i++){
            if(!tr(u,a[i]-'a')) u=tr(u,a[i]-'a')=++tot;
            else u=tr(u,a[i]-'a');
        }
        tag[u]=1,tp[u]=a.length();
        return ;
    }
    int q[N],l,r;
    void build(){
        l=1,r=0;for(int i=0;i<26;i++) if(tr(0,i)) q[++r]=tr(0,i);
        while(l<=r){
            int u=q[l++];
            for(int i=0;i<26;i++)
                if(tr(u,i)) fl(tr(u,i))=tr(fl(u),i),q[++r]=tr(u,i);
                else tr(u,i)=tr(fl(u),i);
        }
        for(int i=1;i<=tot;i++) ::add(fl(i),i);
        return ;
    }
    #undef tr
    #undef fl
}
int cv[N],id[N],num,sz[N];//
void dfs(int u,int fa,int Cover){
    sz[u]=1,id[u]=++num,cv[u]=tag[u]?u:Cover;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;if(v==fa) continue;dfs(v,u,cv[u]);sz[u]+=sz[v];
    }
    return ;
}
struct Count{
    int ct[N];
    void add(int x){ct[x]++;return ;}
    int query(int x){return ct[x];}
}cnt;
struct treearray{
    int tr[N],V;
    int lowbit(int x){return x&(-x);}
    void add(int x,int d){while(x<=V){tr[x]+=d;x+=lowbit(x);}return ;}
    int sum(int x){int ans=0;while(x){ans+=tr[x];x-=lowbit(x);}return ans;}
}t;
struct Stac{int l,r,p;}st[N];
int ans;
void solve(string a){
    int u=0;for(int i=0;i<a.length();i++){u=ACAM::t[u].ch[a[i]-'a'];t.add(id[u],1);}
    u=0;int top=0;
    for(int i=0;i<a.length();i++){
        u=ACAM::t[u].ch[a[i]-'a'];
        int p;if(i==a.length()-1) p=cv[ACAM::t[u].fail];else p=cv[u];
        if(p){
            int r=i+1;int l=r-tp[p]+1;
            while(top&&l<=st[top].l) top--;
            st[++top]=Stac{l,r,p};
        }
    }
    for(int i=1;i<=top;i++) cnt.add(st[i].p);
    u=0;
    for(int i=0;i<a.length();i++){
        u=ACAM::t[u].ch[a[i]-'a'];
        if(i==a.length()-1){
            int p=cv[ACAM::t[u].fail];
            if(p&&cnt.query(p)==t.sum(id[p]+sz[p]-1)-t.sum(id[p]-1)) ans++;
			cnt.ct[p]=0;
        }
        else if(cv[u]){
            if(cnt.query(cv[u])==t.sum(id[cv[u]]+sz[cv[u]]-1)-t.sum(id[cv[u]]-1)) ans++;
			cnt.ct[cv[u]]=0;
        }
    }
    u=0;for(int i=0;i<a.length();++i) {u=ACAM::t[u].ch[a[i]-'a'];t.add(id[u],-1);}
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(head,-1,sizeof(head));tot=0;
    cin>>n;ACAM::begin();
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) ACAM::add(s[i]);
    ACAM::build();
    num=0;dfs(0,0,0);t.V=num+100;
    ans=0;
    for(int i=1;i<=n;i++) solve(s[i]);
    cout<<ans<<endl;
    return 0;
}