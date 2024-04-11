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
        int temp;
        for(int i=0;i<n;i++)
            cin>>temp;
        cout<<3*n<<"\n";
        for(int i=1;i<=n;i+=2)
            for(int c:{1,2,1,1,2,1})
                cout<<c<<" "<<i<<" "<<i+1<<"\n";
    }
}