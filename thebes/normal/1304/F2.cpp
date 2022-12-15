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
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)

const int MN = 55, MM = 2e4+5;
int arr[MN][MM], dp[MN][MM], ps[MM], pre[MM], lz[5*MM], st[5*MM], n, m, k, i, j;

void build(int i,int s,int e,int r){
    if(s!=e){
        build(2*i,s,(s+e)/2,r);
        build(2*i+1,(s+e)/2+1,e,r);
        st[i]=max(st[2*i],st[2*i+1]);
    }
    else st[i]=dp[r+1][s];
    lz[i] = 0;
}

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        st[i] += lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i] = 0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i] = val;
        upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss) upd(2*i+1,(s+e)/2+1,e,ss,se,val),upd_lz(2*i,s,(s+e)/2);
        else if((s+e)/2>=se) upd(2*i,s,(s+e)/2,ss,se,val),upd_lz(2*i+1,(s+e)/2+1,e);
        else upd(2*i,s,(s+e)/2,ss,se,val),upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        st[i]=max(st[2*i],st[2*i+1]);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=n;i>=1;i--){
        build(1,1,m,i);
        for(j=1;j<=m;j++) ps[j]=arr[i][j]+ps[j-1];
        for(j=1;j<=k;j++) upd(1,1,m,max(j-k+1,1),j,-pre[j]+pre[j-1]);
        for(j=1;j<=m;j++){
            dp[i][j]=ps[min(m,j+k-1)]-ps[j-1]+pre[min(m,j+k-1)]-pre[j-1]+st[1];
            if(j+k<=m) upd(1,1,m,max(j+1,1),min(m,j+k),-pre[j+k]+pre[j+k-1]);
            upd(1,1,m,max(j-k+1,1),min(m,j),pre[j]-pre[j-1]);
        }
        swap(ps,pre);
    }
    int ans = 0;
    for(j=1;j<=m;j++) ans=max(ans,dp[1][j]);
    printf("%d\n",ans);
    return 0;
}