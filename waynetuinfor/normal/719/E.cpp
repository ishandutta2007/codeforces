#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define endl '\n'
#define el putchar('\n')
#define spc putchar(' ')
#define mid ((l+r)>>1)
#define xm ((x1+x2)/2)
#define ym ((y1+y2)/2)
#define SS stringstream
#define PQ priority_queue
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define FASTCPP ios_base::sync_with_stdio(0); cin.tie(0)

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<'\n'
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<'\n'
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , "<<#b<<" = "<<(b)<<" , "<<#c<<" = "<<(c)<<" , "<<#d<<" = "<<(d)<<'\n'
#define DEB(...) printf(__VA_ARGS__)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto it:mp)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto it:s)ostm<<*it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

inline int lowbit(int &x){return x&-x;}
inline ll lowbit(ll &x){return x&-x;}
template<typename T>
inline T _pow(T b,int n){
    T a=1; while(n){
        if(n&1)a*=b; b*=b,n>>=1;
    } return a;
}
template<typename T>
inline T _pow(T b,int n,T mod){
    T a=1%mod; while(n){
        if(n&1)a=a*b%mod; b=b*b%mod,n>>=1;
    } return a;
}

inline int gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T& x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c-'0');
    while(c=getchar(), c>='0' && c<='9')x=x*10+c-'0';
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x);pit(args...);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

struct Fib{
    ll ar[2][2];
    Fib(){
        memset(ar,0,sizeof(ar));
    }
    Fib operator+(const Fib &a)const{
        Fib rt=*this;
        rt.ar[0][0]+=a.ar[0][0]; rt.ar[0][0]%=mod;
        rt.ar[0][1]+=a.ar[0][1]; rt.ar[0][1]%=mod;
        rt.ar[1][0]+=a.ar[1][0]; rt.ar[1][0]%=mod;
        rt.ar[1][1]+=a.ar[1][1]; rt.ar[1][1]%=mod;
        return rt;
    }
    Fib operator*(const Fib &a)const{
        Fib rt;
        rt.ar[0][0]=this->ar[0][0]*a.ar[0][0] + this->ar[0][1]*a.ar[1][0]; rt.ar[0][0]%=mod;
        rt.ar[0][1]=this->ar[0][0]*a.ar[0][1] + this->ar[0][1]*a.ar[1][1]; rt.ar[0][1]%=mod;
        rt.ar[1][0]=this->ar[1][0]*a.ar[0][0] + this->ar[1][1]*a.ar[1][0]; rt.ar[1][0]%=mod;
        rt.ar[1][1]=this->ar[1][0]*a.ar[0][1] + this->ar[1][1]*a.ar[1][1]; rt.ar[1][1]%=mod;
        return rt;
    }
    operator bool(){
        if(ar[0][0]>1 || ar[1][1]>1)return 1;
        if(ar[1][0]>0 || ar[0][1]>0)return 1;
        return 0;
    }
    ll gt(){return ar[1][0];}
} I,Fib1;
Fib fibpow(int n,Fib a=I,Fib b=Fib1){
    while(n>0){
        if(n&1)a=a*b;
        b=b*b;
        n>>=1;
    }
    return a;
}
struct node{
    node *l,*r;
    Fib val,tag;
    node():l(NULL),r(NULL){memset(&val,0,sizeof(Fib)); tag=I;};
} *root;

int a[100005];

void build(node *now,int l,int r){
    now->tag=I;
    if(l==r){
        now->val=fibpow(a[l]);
        return ;
    }
    now->l=new node(), now->r=new node();
    build(now->l,l,mid), build(now->r,mid+1,r);
    now->val = now->l->val + now->r->val;
    // cout<<"DE  "<<l<<" "<<r<<" "<<now->val.gt()<<endl;
}
void push(node *now){
    if(now->tag){
        if(now->l)now->l->tag = now->l->tag*now->tag, now->l->val = now->l->val*now->tag;
        if(now->r)now->r->tag = now->r->tag*now->tag, now->r->val = now->r->val*now->tag;
        now->tag=I;
    }
}
void modify(node *now,int l,int r,int ml,int mr,Fib v){
    push(now);
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->val = now->val*v;
        now->tag = now->tag*v;
        return ;
    }
    modify(now->l,l,mid,ml,mr,v), modify(now->r,mid+1,r,ml,mr,v);
    now->val = now->l->val + now->r->val;
}
ll query(node *now,int l,int r,int ql,int qr){
    push(now);
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr){
        return now->val.gt();
    }
    return (query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr))%mod;
}

int main(){
    I.ar[0][0]=I.ar[1][1]=1, I.ar[0][1]=I.ar[1][0]=0;
    Fib1.ar[0][0]=Fib1.ar[1][0]=Fib1.ar[0][1]=1, Fib1.ar[1][1]=0;
    int n,m;rit(n,m);
    for(int i=1;i<=n;++i)rit(a[i]);
    build(root=new node(),1,n);
    while(m--){
        int tp,l,r,x;rit(tp);
        if(tp==1){
            rit(l,r,x);
            modify(root,1,n,l,r,fibpow(x));
        }
        else{
            rit(l,r);
            pln(query(root,1,n,l,r));el;
        }
    }
}