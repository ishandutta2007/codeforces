#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

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
        sort(a+1,a+n+1);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            s+=a[i];
            if(s==x)
                swap(a[i],a[n]);
        }
        if(s==x)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
    }
}