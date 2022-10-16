#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 400000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gcd(int x,int y) {return x?gcd(y%x,x):y;}

int n;
int d=0;
int base;

int check(int pos)
{
    ll x=base+1ll*(n-pos)*d;
    if(x>1000000000) return 0;
    if(x<0) return 1;
    printf("> %I64d\n",x);fflush(stdout);
    int ans; scanf("%d",&ans);
    assert(ans!=-1);
    return ans;
}

int lb(int l,int r)
{
    r++;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(check(mid)==1) r=mid;
        else l=mid+1;
    }
    return l-1;
}

int main()
{
    scanf("%d",&n);
    puts("? 1");fflush(stdout);
    scanf("%d",&base);
    rep(i,1,37)
    {
        int id=(int)(rng()%n)+1;
        printf("? %d\n",id);fflush(stdout);
        int x; scanf("%d",&x);
        d=gcd(d,abs(x-base));
    }
    int pos=lb(1,n);
    printf("! %d %d\n",base-(pos-1)*d,d);fflush(stdout);
    return 0;
}