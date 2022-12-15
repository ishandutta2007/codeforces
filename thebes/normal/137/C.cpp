#include <bits/stdc++.h>
using namespace std;

namespace debug{
    void __(short x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class P1,class P2>
    void __(const pair<P1,P2>&x){__("("),__(x.first),__(", "),__(x.second),__(")");}
    template<class T>
    void __(const vector<T>&x){__("{");bool _ffs=0;for(const auto&v:x)__(_ffs?", ":""),__(v),_ffs=1;__("}");}
    void screm(){__("\n");}
    template<class T1,class... T2>
    void screm(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" | "),screm(t2...);else __("\n");}
    void pr(){__("\n");}
    template<class T1,class... T2>
    void pr(const T1&t1,const T2&...t2){__(t1);if(sizeof...(t2))__(" "),pr(t2...);else __("\n");}

}

using namespace debug;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(x);i>=(y);i--)

const int MN = 1e5+5;
map<int,int> mp;
int st[6*MN], n, m, i, ord[MN], ans;
pii arr[MN];

void upd(int i,int s,int e,int ind){
    if(s!=e){
        if((s+e)/2<ind) upd(2*i+1,(s+e)/2+1,e,ind);
        else upd(2*i,s,(s+e)/2,ind);
        st[i]=st[2*i]+st[2*i+1];
    }
    else st[i]++;
}

int qu(int i,int s,int e,int ss,int se){
    if(ss>se) return 0;
    if(s>=ss&&e<=se) return st[i];
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else return qu(2*i,s,(s+e)/2,ss,se)+qu(2*i+1,(s+e)/2+1,e,ss,se);
}

int main(){
    scanf("%d",&n);
    fox(i,1,n){
        scanf("%d%d",&arr[i].first,&arr[i].second);
        mp[arr[i].first]=mp[arr[i].second]=0;
        ord[i] = i;
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++) it->second=++i;
    m = mp.size();
    sort(ord+1,ord+n+1,[](int i,int j){return arr[i].first<arr[j].first;});
    fox(i,1,n){
        int x = ord[i];
        if(qu(1,1,m,mp[arr[x].second]+1,m)) ans++;
        upd(1,1,m,mp[arr[x].second]);
    }
    pr(ans);
    return 0;
}