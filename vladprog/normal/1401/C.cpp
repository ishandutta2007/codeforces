#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

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
            cin>>a[i],
            b[i]=a[i];
        sort(b+1,b+n+1);
        int m=b[1];
        bool yes=true;
        for(int i=1;i<=n;i++)
            if(a[i]!=b[i]&&
               a[i]%m)
                yes=false;
        cout<<(yes?"YES\n":"NO\n");
    }
}