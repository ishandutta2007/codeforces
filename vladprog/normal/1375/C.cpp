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
        vector<int> a;
        while(n--)
        {
            int x;
            cin>>x;
            a.push_back(x);
            while(a.size()>=2&&
                  a[a.size()-1]>a[a.size()-2])
                if(a.size()==2)
                    a.pop_back();
                else
                    a.erase(a.end()-2);
        }
        if(a.size()==1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}