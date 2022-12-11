#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct seg{
    int ls[N<<5],rs[N<<5],ct;
    void modify(int &rt,int l,int r,int x){
        if(!rt)rt=++ct;
        if(l==r)return;
        int mid=(l+r)>>1;
        if(x<=mid)modify(ls[rt],l,mid,x);
        else modify(rs[rt],mid+1,r,x);
    }
    int query(int rt,int l,int r,int L,int R){
        if(L>R)return 0;
        if(!rt)return 0;
        if(L<=l&&r<=R)return 1;
        int mid=(l+r)>>1,res=0;
        if(L<=mid)res|=query(ls[rt],l,mid,L,R);
        if(R>mid)res|=query(rs[rt],mid+1,r,L,R);
        return res;
    }
    int merge(int x,int y){
        if(!x||!y)return x|y;
        int res=++ct;
        ls[res]=merge(ls[x],ls[y]);
        rs[res]=merge(rs[x],rs[y]);
        return res;
    }
}tr;
struct node{
    int link,len,to[26];
    node(){
        link=len=0;
        memset(to,0,sizeof to);
    }
};
struct SAM{
    struct edge{
        int to,nxt;
    };
    edge ed[N<<2];
    int cnt,h[N<<1];
    void add(int st,int et){
        cnt++;
        ed[cnt].to=et;
        ed[cnt].nxt=h[st];
        h[st]=cnt;
    }
    node t[N<<1];
    int last,siz,hg[N<<1],rt[N<<1];
    SAM(){t[0].len=0,t[0].link=-1;siz=1,last=0;}
    void ins(int x){
        int now=siz++;
        t[now].len=t[last].len+1;
        int p=last;
        while(p!=-1&&!t[p].to[x]){
            t[p].to[x]=now;
            p=t[p].link;
        }
        if(p==-1){
            t[now].link=0;
        }
        else{
            int q=t[p].to[x];
            if(t[p].len+1==t[q].len){
                t[now].link=q;
            }
            else{
                int cl=siz++;
                t[cl]=t[q];
                t[cl].len=t[p].len+1;
                while(p!=-1&&t[p].to[x]==q){
                    t[p].to[x]=cl;
                    p=t[p].link;
                }
                t[q].link=t[now].link=cl;
            }
        }
        last=now;
    }
    void mark(string s){
        int now=0,cp=0;
        for(auto it:s){
            now=t[now].to[it-'a'];
            hg[now]=++cp;
        }
    }
    void build(){
        for(int i=1;i<=siz;i++){
            add(t[i].link,i);
        }
    }
    void dfs(int x,int fa){
        if(hg[x])tr.modify(rt[x],1,n,hg[x]);
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(v==fa)continue;
            dfs(v,x);
            rt[x]=tr.merge(rt[x],rt[v]);
        }
    }
}ty;
string s;
int q;
int main(){
    cin>>s;
    n=s.size();
    for(auto it:s)ty.ins(it-'a');
    ty.mark(s);
    ty.build();
    ty.dfs(0,0);
    scanf("%d",&q);
    while(q--){
        int l,r,p,now=0;
        string ss;
        cin>>l>>r>>ss;
        ss.push_back('a'-1);
        vector<int>path(1,0);
        for(p=0;p<(int)ss.size()-1;p++){
            int nxt=ty.t[now].to[ss[p]-'a'];
            if(nxt&&tr.query(ty.rt[nxt],1,n,l+p,r)){
                now=nxt;
                path.push_back(now);
            }
            else break;
        }
        string ans="-1";
        for(int i=path.size()-1;i>=0;i--){
            int fd=0;
            for(int o=ss[i]+1-'a';o<26;o++)if(ty.t[path[i]].to[o]&&tr.query(ty.rt[ty.t[path[i]].to[o]],1,n,l+i,r)){fd=1,ans=ss.substr(0,i),ans.push_back('a'+o);break;}
            if(fd)break;
        }
        cout<<ans<<endl;
    }
    return  0;
}