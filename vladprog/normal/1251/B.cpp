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

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int k0=0;
        bool ok=false;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            if(s.size()%2)
                ok=true;
            k0+=count(s.begin(),s.end(),'0');
        }
        cout<<n-1+(ok||k0%2==0)<<"\n";
    }
}