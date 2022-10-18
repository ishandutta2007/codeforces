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
        int s;
        cin>>s;
        int ans=0;
        while(s>=10)
        {
            int x=s/10*10;
            ans+=x;
            s-=x;
            s+=x/10;
        }
        cout<<ans+s<<"\n";
    }
}