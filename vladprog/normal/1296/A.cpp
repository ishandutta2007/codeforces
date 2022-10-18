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
        int n;
        cin>>n;
        bool is[2]={};
        int sum=0;
        while(n--)
        {
            int x;
            cin>>x;
            sum+=x;
            is[x%2]=true;
        }
        if(sum%2||is[0]&&is[1])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}