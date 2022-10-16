#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
typedef long double LL;

typedef array<int,19> State;
typedef pair<int,int> P;

const db eps=1e-7;

P operator +(const P &a,const P &b) {return mp(a.FI+b.FI,a.SE+b.SE);}
P operator -(const P &a,const P &b) {return mp(a.FI-b.FI,a.SE-b.SE);}
P operator *(const P &a,const int &b) {return mp(a.FI*b,a.SE*b);}

int n;

set<P> pts[510][20];
map<P,State> seq[510][20];

void dfs(int dep,State &st)
{
    if(dep>n/2)
    {
        State Y{};
        rep(i,1,n/2) Y[i]=Y[i-1]+st[i];
        rep(i,1,n/2) if(Y[i]<0) return;
        P p;
        int S=0;
        rep(i,1,n/2)
        {
            int y=min(Y[i-1],Y[i]);
            S+=2*y+1;
            P q=mp((i*2-1)*(2*y+1),3*y*y+3*y+1);
            p=p+q;
        }
        assert(S<=324);
        pts[S][Y[n/2]].insert(p);
        seq[S][Y[n/2]][p]=st;
        //fprintf(stderr,"? %d, %d: %d\n",p.FI,p.SE,S);
        //rep(i,1,n/2) fprintf(stderr,"%d ",Y[i]);
        //fprintf(stderr,"\n");
        return;
    }
    st[dep]=1;
    dfs(dep+1,st);
    st[dep]=-1;
    dfs(dep+1,st);
}

int main()
{
    db x,y; scanf("%d%lf%lf",&n,&x,&y); x*=2.0; y*=3.0;
    State dum{};
    dfs(1,dum);
    rep(S1,1,324) rep(h,0,n/2) for(auto p: pts[S1][h]) rep(S2,1,324)
    {
        int S=S1+S2;
        db X=x*S,Y=y*S;
        int xi=round(X),yi=round(Y);
        //if(S1==3 && S2==7) fprintf(stderr,"?? %d %d %.10f %.10f\n",xi,yi,X,Y);
        if(fabs(xi-X)<=eps && fabs(yi-Y)<=eps)
        {
            P A={xi,yi};
            P q=A-p;
            q.FI=2*n*S2-q.FI;
            //if(S1==3 && S2==7) fprintf(stderr,"?? %d %d\n",q.FI,q.SE);
            if(pts[S2][h].find(q)!=pts[S2][h].end())
            {
                State a=seq[S1][h][p];
                State b=seq[S2][h][q];
                rep(i,1,n/2) putchar(a[i]==1?'(':')');
                per(i,1,n/2) putchar(b[i]==-1?'(':')');
                puts("");
                return 0;
            }
        }
    }
    return 0;
}