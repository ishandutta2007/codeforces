#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll cross(int a1,int b1,int a2,int b2,int a3,int b3) 
{
    return 1ll*(a2*a3-a1*a3)*(b1*b3-b1*b2)-1ll*(b2*b3-b1*b3)*(a1*a3-a1*a2);
}

pii v[maxn+5];
int sta[maxn+5],top;
bool mark[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&v[i].FI,&v[i].SE);
    vi id; rep(i,1,n) id.pb(i);
    sort(id.begin(),id.end(),[](int a,int b){return v[a]>v[b];});
    vi tmp;
    for(auto i: id) if(tmp.empty() || (v[tmp.back()].FI==v[i].FI && v[tmp.back()].SE==v[i].SE) || (v[tmp.back()].FI>v[i].FI && v[tmp.back()].SE<v[i].SE)) tmp.pb(i);
    id=tmp;
    for(auto i: id) 
    {
        while(top>1 && cross(v[i].FI,v[i].SE,v[sta[top]].FI,v[sta[top]].SE,v[sta[top-1]].FI,v[sta[top-1]].SE)>0) top--;
        if(top==0 || v[i]!=v[sta[top]]) sta[++top]=i;
    }
    rep(i,1,top) mark[sta[i]]=1;
    int M=id.size();
    rep(i,1,M-1) if(mark[id[i-1]] && v[id[i]]==v[id[i-1]]) mark[id[i]]=1;
    vi ans;
    rep(i,1,n) if(mark[i]) ans.pb(i);
    int N=ans.size();
    rep(i,0,N-1) printf("%d%c",ans[i]," \n"[i==N-1]);
    return 0;
}