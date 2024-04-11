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
        multiset<int,greater<>> s;
        while(n--)
        {
            int a;
            cin>>a;
            s.insert(a);
        }
        int prv=0,pl=0;
        while(!s.empty())
        {
            pl=!pl;
            int cur=*s.begin();
            s.erase(s.begin());
            cur--;
            if(prv>0)
                s.insert(prv);
            prv=cur;
        }
        cout<<(pl?"T\n":"HL\n");
    }
}