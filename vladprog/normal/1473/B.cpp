#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        string s,t;
        cin>>s>>t;
        string ans;
        for(int i=0;;i++)
        {
            char x=s[i%s.size()];
            char y=t[i%t.size()];
            if(x==y)
                ans+=x;
            else
            {
                ans="-1";
                break;
            }
            if(ans.size()%s.size()==0&&
               ans.size()%t.size()==0)
                break;
        }
        cout<<ans<<"\n";
    }
}