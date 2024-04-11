#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N=100050;
const int M=20*N;

int n,m,ls[M],rs[M],st[M],root,tsz;
void Set(int&c,int ss,int se,int qi,int x){
    if(!c)c=++tsz;st[c]+=x;
    if(ss==se)return;
    int mid=ss+se>>1;
    if(qi<=mid)Set(ls[c],ss,mid,qi,x);
    else Set(rs[c],mid+1,se,qi,x);
}
int Get(int c,int ss,int se,int qs,int qe){
    if(se<qs||ss>qe)return 0;
    if(qs<=ss&&se<=qe)return st[c];
    int mid=ss+se>>1;
    return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}

struct Event{
    int p,t,yl,yr;
    bool operator<(const Event& ev)const {
        if(p==ev.p)return t<ev.t;
        else return p<ev.p;
    }
};

int main(){
    scanf("%i%i",&n,&m);
    ll ans=1;
    vector<Event> events;
    for(int i=1;i<=n;i++){
        int y,lx,rx;
        scanf("%i%i%i",&y,&lx,&rx);
        if(lx==0&&rx==1e6)ans++;
        events.pb({lx,1,y,0});
        events.pb({rx+1,0,y,0});
    }
    for(int i=1;i<=m;i++){
        int x,ly,ry;
        scanf("%i%i%i",&x,&ly,&ry);
        if(ly==0&&ry==1e6)ans++;
        events.pb({x,2,ly,ry});
    }
    sort(events.begin(),events.end());
    for(int i=0;i<events.size();i++){
        if(events[i].t==0){
            Set(root,0,1e6,events[i].yl,-1);
        }else if(events[i].t==1){
            Set(root,0,1e6,events[i].yl,1);
        }else{
            ans+=Get(root,0,1e6,events[i].yl,events[i].yr);
        }
    }
    printf("%lld",ans);
    return 0;
}