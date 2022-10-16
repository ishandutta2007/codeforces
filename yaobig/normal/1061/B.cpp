#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    ll sum=0;
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n) sum+=a[i];
    sort(a+1,a+n+1);
    int st=0;
    rep(i,1,n)
    {
        if(st<a[i]) st++;
    }
    sum-=n+a[n]-st;
    printf("%I64d\n",sum);
    return 0;
}