#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 5e5+5;
const ld PI = (ld)4*atan((ld)1), eps = (ld)5e-19;
int N, R, i, j, x, y, cnt, nxt; ld st[3*MN];
map<ld,int> mp; set<ld> pnt[MN];
ld aa[MN], bb[MN]; pii pos[MN];
struct qur{int t, x, y;}q[MN];

ll dot(pii i,pii j){return 1LL*i.F*j.F+1LL*i.S*j.S;}

bool ok(int i,int j){
    pii v1, v2;
    if(aa[i]<aa[j]) v1={pos[i].F+R,pos[i].S};
    else v1={pos[j].F+R,pos[j].S};
    if(bb[i]<bb[j]) v2={pos[i].F-R,pos[i].S};
    else v2={pos[j].F-R,pos[j].S};
    return dot(v1,v2)>=0;
}

void upd(int i,int s,int e,int ind,ld val,bool del=0){
    if(s!=e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind,val,del);
        else upd(2*i,s,(s+e)/2,ind,val,del);
        st[i]=max(st[2*i],st[2*i+1]);
    }
    else{
        if(del) pnt[s].erase(val);
        else pnt[s].insert(val);
        if(pnt[s].empty()) st[i]=-1;
        else{
            auto it=pnt[s].end(); it--;
            st[i]=*it;
        }
    }
}

ld qu(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return max(qu(2*i,s,(s+e)/2,ss,se),qu(2*i+1,(s+e)/2+1,e,ss,se));
}

int main(){
    scanf("%d%d",&R,&N);
    for(i=1;i<=N;i++){
        scanf("%d%d",&q[i].t,&q[i].x);
        if(q[i].t==1){
            cnt ++;
            scanf("%d",&q[i].y);
            pos[cnt] = {q[i].x, q[i].y};
            aa[cnt] = (ld)atan2((ld)q[i].y,(ld)q[i].x+R);
            bb[cnt] = PI-(ld)atan2((ld)q[i].y,(ld)q[i].x-R);
            //printf(">>> %.20Lf %.20Lf\n",aa[cnt],bb[cnt]);
            mp[aa[cnt]]=0;
        }
        else if(q[i].t==3)
            scanf("%d",&q[i].y);
    }
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++nxt;
    cnt = 0;
    for(i=1;i<=N;i++){
        if(q[i].t==1){
            cnt ++;
            upd(1,1,nxt,mp[aa[cnt]],bb[cnt],0);
        }
        else if(q[i].t==2){
            upd(1,1,nxt,mp[aa[q[i].x]],bb[q[i].x],1);
        }
        else{
            x=q[i].x, y=q[i].y;
            if(!ok(x,y)) printf("NO\n");
            else{
                ld ix=min(aa[x],aa[y]);
                ld iy=min(bb[x],bb[y]);
                int inx = mp[ix];
                upd(1,1,nxt,mp[aa[x]],bb[x],1);
                upd(1,1,nxt,mp[aa[y]],bb[y],1);
                if(qu(1,1,nxt,inx,nxt)>=iy) printf("NO\n");
                else printf("YES\n");
                upd(1,1,nxt,mp[aa[x]],bb[x],0);
                upd(1,1,nxt,mp[aa[y]],bb[y],0);
            }
        }
    }
    return 0;
}