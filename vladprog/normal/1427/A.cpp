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
        vector<int> p,m,z;
        int sum_p=0,sum_m=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(a>0)
                p.push_back(a),
                sum_p+=a;
            else if(a<0)
                m.push_back(a),
                sum_m-=a;
            else
                z.push_back(a);
        }
        if(sum_p==sum_m)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
            if(sum_p<sum_m)
                swap(p,m);
            for(int x:p)
                cout<<x<<" ";
            for(int x:m)
                cout<<x<<" ";
            for(int x:z)
                cout<<x<<" ";
            cout<<"\n";
        }
    }
}