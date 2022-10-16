#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];
int L1[maxn+5],L2[maxn+5];
int cnt[maxn+5];
int t[maxn+5];
char ans[maxn+5];

void add(int x,int v)
{
    for(;x<=maxn;x+=x&-x) t[x]=max(t[x],v);
}
int ask(int x)
{
    int res=0;
    for(;x;x-=x&-x) res=max(res,t[x]);
    return res;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);

    int ML=0;
    rep(i,1,n)
    {
        L1[i]=ask(a[i]-1)+1;
        add(a[i],L1[i]);
        ML=max(ML,L1[i]);
    }
    memset(t,0,sizeof t);
    per(i,1,n)
    {
        L2[i]=ask(maxn-a[i])+1;
        add(maxn+1-a[i],L2[i]);
    }
    rep(i,1,n) if(L1[i]+L2[i]-1==ML) cnt[L1[i]]++;
    rep(i,1,n)
    {
        if(L1[i]+L2[i]-1!=ML) ans[i]='1';
        else
        {
            if(cnt[L1[i]]>1) ans[i]='2';
            else ans[i]='3';
        }
    }
    puts(ans+1);
    return 0;
}