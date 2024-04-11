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
        while(n--)
        {
            int a;
            cin>>a;
            is[a%2]=true;
        }
        cout<<(is[0]&&is[1]?"NO\n":"YES\n");
    }
}