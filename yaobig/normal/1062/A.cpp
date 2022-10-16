#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 100
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5],b[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    a[0]=0;
    a[n+1]=1001;
    rep(i,1,n+1) if(a[i]==a[i-1]+1) b[i]=1;
    int ans=0,cons=0;
    rep(i,1,n+1)
        if(b[i]) cons++,ans=max(ans,cons);
        else cons=0;
    printf("%d\n",max(ans-1,0));
    return 0;
}