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

const int MN = 2e5+5;
int n, ans, sh, i, x, arr[MN], st[3*MN], id[3*MN], dp[3*MN], lz[3*MN], p[MN], l[MN], r[MN], f, s;

void build(int i,int s,int e){
    if(s!=e){
        build(2*i,s,(s+e)/2);
        build(2*i+1,(s+e)/2+1,e);
        id[i]=(st[2*i]>st[2*i+1])?id[2*i]:id[2*i+1];
        st[i]=max(st[2*i],st[2*i+1]);
    }
    else st[i]=-arr[s],id[i]=s;
}

pii qu(int i,int s,int e,int ss,int se){
    if(s>=ss&&e<=se) return make_pair(st[i],id[i]);
    else if((s+e)/2<ss) return qu(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qu(2*i,s,(s+e)/2,ss,se);
    else{
        pii l=qu(2*i,s,(s+e)/2,ss,se), r=qu(2*i+1,(s+e)/2+1,e,ss,se);
        return l.first>r.first?l:r;
    }
}

inline void upd_lz(int i,int s,int e){
    if(lz[i]){
        dp[i] += lz[i];
        if(s!=e) lz[2*i]+=lz[i],lz[2*i+1]+=lz[i];
        lz[i] = 0;
    }
}

void upd(int i,int s,int e,int ss,int se,int val){
    if(ss>se) return;
    upd_lz(i,s,e);
    if(s>=ss&&e<=se){
        lz[i]=val;
        upd_lz(i,s,e);
    }
    else{
        if((s+e)/2<ss){
            upd_lz(2*i,s,(s+e)/2);
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        }
        else if((s+e)/2>=se){
            upd_lz(2*i+1,(s+e)/2+1,e);
            upd(2*i,s,(s+e)/2,ss,se,val);
        }
        else{
            upd(2*i,s,(s+e)/2,ss,se,val);
            upd(2*i+1,(s+e)/2+1,e,ss,se,val);
        }
        dp[i]=max(dp[2*i],dp[2*i+1]);
    }
}

int qur(int i,int s,int e,int ss,int se){
    upd_lz(i,s,e);
    if(s>=ss&&e<=se) return dp[i];
    else if((s+e)/2<ss) return qur(2*i+1,(s+e)/2+1,e,ss,se);
    else if((s+e)/2>=se) return qur(2*i,s,(s+e)/2,ss,se);
    else return max(qur(2*i,s,(s+e)/2,ss,se),qur(2*i+1,(s+e)/2+1,e,ss,se));
}

int init(int s,int e,int d){
    if(s>e) return 0;
    int rt = qu(1,1,n,s,e).second;
    upd(1,1,n,rt,rt,d);
    int ls = init(s,rt-1,d+1), rs = init(rt+1,e,d+1);
    p[ls] = p[rs] = rt;
    l[rt] = ls, r[rt] = rs;
    return rt;
}

int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    build(1,1,n);
    init(1,n,1);
    ans = qur(1,1,n,1,n);
    int lst = 1;
    for(i=0;i<n-1;i++){
        if(!p[n-i]) upd(1,1,n,1,n,-1);
        else if(p[n-i]<=n-i) upd(1,1,n,p[n-i]+1,n-i-1,-1);
        else upd(1,1,n,p[n-i]+1,n,-1),upd(1,1,n,1,n-i-1,-1);
        upd(1,1,n,n-i,n-i,-qur(1,1,n,n-i,n-i));
        r[p[n-i]]=l[n-i];
        p[l[n-i]]=p[n-i];
        l[n-i]=0;
        int c = lst;
        while(arr[c]>arr[n-i]&&p[c]) c=p[c];
        if(arr[c]>arr[n-i]){
            upd(1,1,n,1,n,1);
            p[n-i] = 0;
            r[n-i] = c;
            p[c] = n-i;
        }
        else{
            p[n-i] = c;
            r[n-i] = l[c];
            l[c] = n-i;
            p[r[n-i]] = n-i;
            upd(1,1,n,n-i,n-i,qur(1,1,n,c,c)+1);
            if(c>=n-i) upd(1,1,n,n-i+1,c-1,1);
            else upd(1,1,n,n-i+1,n,1), upd(1,1,n,1,c-1,1);
        }
        int tmp = qur(1,1,n,1,n);
        if(tmp<ans){
            ans = tmp;
            sh = n-i-1;
        }
        lst = n-i;
    }
    printf("%d %d\n",ans,sh);
    return 0;
}