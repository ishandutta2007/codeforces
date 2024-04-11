#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

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
        if(n==1)
        {
            cout<<1<<"\n";
            continue;
        }
        cout<<2<<"\n";
        cout<<n<<" "<<n-1<<"\n";
        for(int i=n;i-2>=1;i--)
            cout<<i<<" "<<i-2<<"\n";
    }
}