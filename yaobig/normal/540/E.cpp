#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi vec;
int l[maxn+5],r[maxn+5];
int a[maxn+5];
int getid(int x) {return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;}

int t[maxn+5];
void add(int x)
{
    for(;x<=maxn;x+=x&-x) t[x]++;
}
int ask(int x)
{
    int res=0;
    for(;x;x-=x&-x) res+=t[x];
    return res;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
    rep(i,1,n) vec.pb(l[i]),vec.pb(r[i]);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int N=vec.size();

    rep(i,1,N) a[i]=vec[i-1];
    rep(i,1,n) swap(a[getid(l[i])],a[getid(r[i])]);

    ll ans=0;
    per(i,1,N)
    {
        int id=getid(a[i]);
        ans+=ask(id);
        add(id);
        int L=i,R=id;
        if(L>R) swap(L,R);
        ans+=vec[R-1]-vec[L-1]-(R-L);
        //printf("%d: %d, %d\n",i,L,R);
    }

    printf("%I64d\n",ans);
    return 0;
}