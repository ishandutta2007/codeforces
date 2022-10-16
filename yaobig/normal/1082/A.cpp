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

int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {

        int n,x,y,d;
        scanf("%d%d%d%d",&n,&x,&y,&d);
        int ans=inf;
        if(abs(x-y)%d==0) ans=min(ans,abs(x-y)/d);
        if(abs(1-y)%d==0) ans=min(ans,abs(1-y)/d+(x-1+d-1)/d);
        if(abs(n-y)%d==0) ans=min(ans,abs(n-y)/d+(n-x+d-1)/d);
        if(ans==inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}