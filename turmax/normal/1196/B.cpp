#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    int n,m;
    vector <int> a;
    vector <int> res;
    int k;
    int s;
    int l;
    for(int i=0;i<q;++i)
    {
        res.clear();
        cin>>n>>m;
        a.resize(n);
        s=0;
        l=0;
        for(int j=0;j<n;++j)
        {
            cin>>k;
            a[j]=k;
            s+=k;
            if((s%2)!=(l%2))
            {
                l=s;
                res.push_back(j+1);
            }
        }
        if(res.size()<m)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if((s%2)==(m%2))
            {
                cout<<"YES"<<endl;
                for(int i=0;i<(m-1);++i)
                {
                    cout<<res[i]<<" ";
                }
                cout<<n<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}