// LUOGU_RID: 96126953
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,root[N<<1];
struct seg{
    pair<int,int>t[N<<4];
    int ls[N<<4],rs[N<<4],ct;
    void pushup(int rt){t[rt]=max(t[ls[rt]],t[rs[rt]]);}
    void modify(int &rt,int l,int r,int x){
        if(!rt)rt=++ct;
        if(l==r)return t[rt].first++,t[rt].second=-l,void();
        int mid=(l+r)>>1;
        if(x<=mid)modify(ls[rt],l,mid,x);
        else modify(rs[rt],mid+1,r,x);
        pushup(rt);
    }
    int merge(int x,int y,int l,int r){
        if(!x||!y)return x|y;
        int res=++ct,mid=(l+r)>>1;
        if(l==r)return t[res].first=t[x].first+t[y].first,t[res].second=-l,res;
        ls[res]=merge(ls[x],ls[y],l,mid);
        rs[res]=merge(rs[x],rs[y],mid+1,r);
        pushup(res);
        return res;
    }
    pair<int,int>query(int rt,int l,int r,int L,int R){
        if(!rt)return {-1,1};
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        if(R<=mid)return query(ls[rt],l,mid,L,R);
        if(L>mid)return query(rs[rt],mid+1,r,L,R);
        return max(query(ls[rt],l,mid,L,R),query(rs[rt],mid+1,r,L,R));
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
    node t[N<<1];
    int siz;
    SAM(){t[0].len=0,t[0].link=-1;siz=1;}
    int ins(int x,int last){
        if(t[last].to[x]){
            int p=last,q=t[p].to[x];
            if(t[p].len+1==t[q].len)return q;
            else{
                int cl=siz++;
                t[cl]=t[q];
                t[cl].len=t[p].len+1;
                while(p!=-1&&t[p].to[x]==q)t[p].to[x]=cl,p=t[p].link;
                t[q].link=cl;
                return cl;
            }
        }
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
        return now;
    }
}ty;
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
void build(){
    for(int i=1;i<=ty.siz;i++){
        add(i,ty.t[i].link);
        add(ty.t[i].link,i);
    }
}
int f[N<<1][22];
void dfs(int x,int fa){
    f[x][0]=fa;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        root[x]=tr.merge(root[x],root[v],1,m);
    }
}
string s,ss[N];
int pos[N];
int main(){
    cin>>s>>m;
    for(int i=1;i<=m;i++){
        cin>>ss[i];
        int last=0;
        for(char ch:ss[i]){
            last=ty.ins(ch-'a',last);
        }
    }
    for(int i=0,now=0;i<(int)s.size();i++){
        pos[i]=now=ty.ins(s[i]-'a',now);
    }
    for(int i=1;i<=m;i++){
        int last=0;
        for(char ch:ss[i])last=ty.ins(ch-'a',last),tr.modify(root[last],1,m,i);
    }
    build();
    dfs(0,0);
    for(int i=1;i<=21;i++)for(int o=1;o<=ty.siz;o++)f[o][i]=f[f[o][i-1]][i-1];
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r,ql,qr;
        scanf("%d%d%d%d",&l,&r,&ql,&qr);
        int kk=pos[qr-1];
        for(int o=21;o>=0;o--){
            if(ty.t[f[kk][o]].len>=(qr-ql+1))kk=f[kk][o];
        }
        if(ty.t[kk].len<(qr-ql+1))printf("%d 0\n",l);
        else{
            auto it=tr.query(root[kk],1,m,l,r);
            if(it.second==1)it={0,-l};
            printf("%d %d\n",-it.second,it.first);
        }
    }
    return 0;
}