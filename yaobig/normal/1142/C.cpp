#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll x[maxn+5],y[maxn+5];
struct P {ll x,y;};
P operator -(const P &a,const P &b) {return P{a.x-b.x,a.y-b.y};}
ll cross(const P &a,const P &b) {return a.x*b.y-a.y*b.x;}

struct monoqueue
{
    pair<P,int> a[maxn+5];
    int head,rear;
    void init() {head=0; rear=-1;}

    monoqueue(){init();}
    void push(P x,int id)
    {
        while(head<rear && cross(x-a[rear].FI,a[rear].FI-a[rear-1].FI)<=0) rear--;
        a[++rear]={x,id};
    }
    void pop()
    {
        while(head<rear && a[head].FI.x==a[head+1].FI.x) head++;
    } 
    int size() {return rear-head+1;}
}q;

P p[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) 
    {
        int x,y; scanf("%d%d",&x,&y);
        p[i]=P{x,y-1ll*x*x};
    }
    sort(p+1,p+n+1,[](const P &a,const P &b){
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y;
    });
    rep(i,1,n) q.push(p[i],i);
    q.pop();
    printf("%d\n",q.size()-1);
    return 0;
}