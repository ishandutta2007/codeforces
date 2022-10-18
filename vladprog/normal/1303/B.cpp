#include<bits/stdc++.h>

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
        int n,g,b;
        cin>>n>>g>>b;
        int k=(n+1)/2;
        int res=(k-1)/g*(g+b)+(k-1)%g+1;
        cout<<max(n,res)<<"\n";
    }
}