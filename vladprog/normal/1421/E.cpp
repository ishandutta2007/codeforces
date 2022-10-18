#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];
pii p[N];
int b[N],c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        p[i].x=a[i],
        p[i].y=(i%2?1:-1);
    if(n==1)
        cout<<a[1],exit(0);
    sort(p+1,p+n+1,greater<pii>());
    for(int i=1;i<=n;i++)
        tie(b[i],c[i])=p[i];
    int sum_b=-accumulate(b+1,b+n+1,0ll);
    int sum_c=-accumulate(c+1,c+n+1,0ll);
    int ans=-1e18;
    for(int i=0;i<=n;i++)
    {
        if((n+i)%3==2)
            if(sum_c!=n)
                ans=max(ans,sum_b);
            else
                ans=max(ans,sum_b-2*b[i]+2*b[i+1]);
        sum_b+=2*b[i+1];
        sum_c+=2*c[i+1];
    }
    cout<<ans;
}