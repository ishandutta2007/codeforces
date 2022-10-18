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

    int n;
    cin>>n;
    if(n%2==0)
    {
        int x=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            x^=a;
        }
        if(x)
            cout<<"NO",exit(0);
    }
    cout<<"YES\n";
    cout<<(n-1)/2*2<<"\n";
    for(int i=1;i<=n-2;i++)
        if(i%2)
            cout<<i<<" "<<i+1<<" "<<i+2<<"\n";
    for(int i=n-2;i>=1;i--)
        if(i%2)
            cout<<i<<" "<<i+1<<" "<<i+2<<"\n";
}