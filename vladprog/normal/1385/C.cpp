#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

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
            cin>>a[i];
        int ans=n-1;
        bool down=false;
        for(int i=n-1;i>=1;i--)
        {
            if(a[i]>a[i+1]&&down)
                break;
            if(a[i]<a[i+1])
                down=true;
            ans=i-1;
        }
        cout<<ans<<"\n";
    }
}