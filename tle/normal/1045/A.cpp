#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 400010;
const int mod = 1e9+7;
const int MAX = 1000000010;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
    x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m,N;

int ID[5010],XX[5050],YY[5050],ZZ[5050];

int Is[5010];

struct Node{
    int l,r,id;
}T[5010<<2];


struct Edge{
    int to,cap;
    Edge *oppo,*next;
};
Edge *E[maxn],Pr[maxn<<2];int cnt=0;
void addedge(int u,int v,int cap){
 //   cout<<u<<' '<<v<<' '<<cap<<endl;
    Pr[++cnt].to=v;Pr[cnt].cap=cap;Pr[cnt].oppo=&Pr[cnt+1];Pr[cnt].next=E[u];E[u]=&Pr[cnt];
    Pr[++cnt].to=u;Pr[cnt].cap=0;  Pr[cnt].oppo=&Pr[cnt-1];Pr[cnt].next=E[v];E[v]=&Pr[cnt];
}
int H[maxn];
int s,t;
bool Makelevel(){
    memset(H,127,sizeof(H));H[s]=0;
    static queue<int> Q;Q.push(s);
    while(!Q.empty()){int u=Q.front();Q.pop();
        for(Edge *P=E[u];P;P=P->next)
            if(P->cap&&H[P->to]>H[u]+1){
                H[P->to]=H[u]+1;
                Q.push(P->to);
            }
    }
    return H[t]!=0x7f7f7f7f;
}

int extend(int u,int left){int r=0;
    if(u==t)return left;
    for(Edge *P=E[u];P&&r<left;P=P->next)
        if(P->cap&&H[P->to]==H[u]+1){int t;
            t=extend(P->to,min(P->cap,left-r));
            r+=t;P->cap-=t;P->oppo->cap+=t;
        }
    if(!r)H[u]=MAX;
    return r;
}


void Work(){
    int ans=0;
    while(Makelevel())ans+=extend(s,MAX);
    iout(ans);
    int num=0;
    REP(i,1,m){
        for(Edge *P=E[i];P;P=P->next)if(P->to==t&&P->cap==0)Is[i]=1,num++;
    }
    assert(num==ans);
    REP(i,1,n)if(ID[i]==2){
        int x;
        for(Edge *P=E[N+i];P;P=P->next)if(P->to==s)x=P->cap;
        if(x==0)continue;
        int now=2;
        for(Edge *P=E[N+i];P;P=P->next)if(P->to<=m&&P->to>=1&&P->cap==0){
            now--;
            printf("%d %d\n",i,P->to);
            Is[P->to]=0;
        }
        int a=XX[i],b=YY[i],c=ZZ[i];
        if(now&&Is[a]){
            Is[a]=0;
            now--;
            printf("%d %d\n",i,a);
        }
        if(now&&Is[b]){
            Is[b]=0;
            now--;
            printf("%d %d\n",i,b);
        }
        if(now&&Is[c]){
            Is[c]=0;
            now--;
            printf("%d %d\n",i,c);
        }
    }
    REP(i,1,n)if(ID[i]==0){
        for(Edge *P=E[N+i];P;P=P->next)if(P->to>=1&&P->to<=m&&P->cap==0&&Is[P->to]){
            Is[P->to]=0;
            printf("%d %d\n",i,P->to);
        }
    }
    REP(i,1,m)if(Is[i]){
        int id=0;
        REP(j,1,n)if(ID[j]==1&&XX[j]<=i&&YY[j]>=i&&(id==0||YY[j]<YY[id]))id=j;
        ID[id]=4;
        printf("%d %d\n",id,i);
        assert(id!=0);
    }
}

void build(int i,int l,int r){
//    cout<<l<<' '<<r<<endl;
    T[i].l=l;T[i].r=r;T[i].id=++N;
    if(l==r){
        addedge(N,l,MAX);
        return;
    }
    int M=l+r>>1;
    build(i<<1,l,M);build(i<<1|1,M+1,r);
    addedge(T[i].id,T[i<<1].id,MAX);addedge(T[i].id,T[i<<1|1].id,MAX);
}

void query(int i,int l,int r,int id){
//    cout<<i<<' '<<T[i].l<<' '<<T[i].r<<endl;
    if(l<=T[i].l&&T[i].r<=r){
        addedge(id,T[i].id,1);
        return;
    }
    int M=T[i].l+T[i].r>>1;
    if(l<=M)query(i<<1,l,r,id);if(r>M)query(i<<1|1,l,r,id);
}

void Init(){
    read(n,m);
    N=m;
 //   cout<<"!\n";
    build(1,1,m);
    s=0;t=m*5+n+1;
    REP(i,1,m)addedge(i,t,1);
    REP(i,1,n){
        int id;
        read(id);
   //     cout<<id<<endl;
        ID[i]=id;
        if(id==0){
            addedge(s,N+i,1);
            int k;
            read(k);
            while(k--){
                int x;
                read(x);
                addedge(N+i,x,1);
            }
        }
        else if(id==1){
            addedge(s,N+i,1);
   //         cout<<"!\n";
            int l,r;
            read(l,r);
            query(1,l,r,N+i);
            XX[i]=l;YY[i]=r;
        }
        else{
            addedge(s,N+i,2);
            int a,b,c;
            read(a,b,c);
            addedge(N+i,a,1);addedge(N+i,b,1);addedge(N+i,c,1);
            XX[i]=a;YY[i]=b;ZZ[i]=c;
        }
    }
}


int main(){
    
    Init();
    int t=0;
    
    Work();
    
    return 0;
}