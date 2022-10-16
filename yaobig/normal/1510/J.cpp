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

char s[maxn+5];
vi A[2];
int n;

void output(vi a)
{
    int N=a.size();
    printf("%d\n",N);
    rep(i,1,N) printf("%d%c",a[i-1]," \n"[i==N]);
}

vi cal(int x)
{
    vi ans;
    while(x>3)
    {
        x-=2; ans.pb(1);
    }
    if(x==0) return ans;
    if(x==2) {ans.pb(1); return ans;}
    if(x==3) {ans.pb(2); return ans;}
    assert(0);
    return vi{};
}

bool check(int t)
{
    int m=A[1].size();
    vi res;
    rep(i,0,m)
    {
        int x=A[0][i]-t;
        if(i>0 && i<m) x--;
        if(x<0) return 0;
        //fprintf(stderr,"?(%d) %d: %d\n",t,i,x);
        if(t==0)
        {
            if(x!=0) return 0;
        }
        else if(t==1)
        {
            if(x%2==1) return 0;
            rep(i,1,x/2) res.pb(1);
        }
        else
        {
            if(x==1) return 0;
            auto Y=cal(x);
            for(auto y: Y) res.pb(y);
        }   

        if(i<m) res.pb(A[1][i]+t);
    }
    output(res);
    return 1;
}

int main()
{
    scanf("%s",s+1); 
    n=strlen(s+1);
    rep(i,1,n) s[i]=s[i]=='_'?0:1;
    int st=0,len=0;
    rep(i,1,n)
    {
        if(st==s[i]) len++;
        else
        {
            A[st].pb(len);
            st^=1; len=1;
        }
    }
    if(st==0) A[0].pb(len);
    else A[1].pb(len),A[0].pb(0);

    if(A[0].size()==1) return puts("0\n"),0;
    rep(i,0,3) if(check(i)) return 0;
    puts("-1");
    return 0;
}