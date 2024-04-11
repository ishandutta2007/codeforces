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
        int n,k;
        cin>>n>>k;
        if(k<=(n+1)/2)
        {
            for(int i=1;i<=n;i++,cout<<"\n")
                for(int j=1;j<=n;j++)
                    if(i==j&&i%2&&(i+1)/2<=k)
                        cout<<'R';
                    else
                        cout<<'.';
        }
        else
            cout<<"-1\n";
    }
}