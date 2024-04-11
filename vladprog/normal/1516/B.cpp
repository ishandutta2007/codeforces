#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010;

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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            a[i]^=a[i-1];
        bool yes=false;
        for(int i=1;i<=n-1;i++)
            if(a[i]==(a[n]^a[i]))
                yes=true;
        for(int i=1;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
                if(a[i]==(a[j]^a[i])&&a[i]==(a[n]^a[j]))
                    yes=true;
        cout<<(yes?"YES\n":"NO\n");
    }
}