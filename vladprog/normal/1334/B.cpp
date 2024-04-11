#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        int ans=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            if(sum>=x*i)
                ans=i;
        }
        cout<<ans<<"\n";
    }
}