#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        int mina=*min_element(a+1,a+n+1);
        int minb=*min_element(b+1,b+n+1);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=max(a[i]-mina,b[i]-minb);
        cout<<ans<<"\n";
    }
}