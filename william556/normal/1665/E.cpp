#include<bits/stdc++.h>
using namespace std;
inline int in(){
    int x;
    scanf("%d",&x);
    return x;
}
const int N=1e5+5;
int n;
int tot,rt[N];
struct node{
    int ls,rs,val;
}t[N*40];
#define ls(x) t[(x)].ls
#define rs(x) t[(x)].rs
#define val(x) t[(x)].val
void ins(int &p,int pre,int v,int d){
    p=++tot;
    t[p]=t[pre];val(p)++;
    if(d==-1)return;
    if(v>>d&1)ins(rs(p),rs(pre),v,d-1);
    else ins(ls(p),ls(pre),v,d-1);
}
int pos;
void get(int p,int q,int d,int v){
    if(d==-1){
        pos=v;
        return;
    }
    if(val(ls(p))-val(ls(q)))get(ls(p),ls(q),d-1,v);
    else get(rs(p),rs(q),d-1,v|1<<d);
}
int ans;
vector<pair<int,int> > vec;
void query(int p,int q,int d,int v){
    if(d==-1){
        ans=min(ans,v);
        return;
    }
    int cnt=val(ls(p))-val(ls(q));
    for(pair<int,int> x:vec)if(x.second&&(x.first>>d&1)==0)cnt++;
    if(cnt>1){
        for(pair<int,int> &x:vec){
            if((x.first>>d&1))x.second=0;
        }
        query(ls(p),ls(q),d-1,v);
        return;
    }
    if(val(ls(p))-val(ls(q))){
        get(ls(p),ls(q),d-1,v);
        vec.push_back(make_pair(pos,1));
    }
    query(rs(p),rs(q),d-1,v|1<<d);
}
void solve(){
    n=in();
    tot=0;
    for(int i=1;i<=n;i++){
        int x=in();
        ins(rt[i],rt[i-1],x,29);
    }
    int q=in();
    while(q--){
        int l=in(),r=in();
        ans=2e9;
        vec.clear();
        query(rt[r],rt[l-1],29,0);
        printf("%d\n",ans);
    }
}
int main(){
    int t=in();
    while(t--)solve();
    return 0;
}