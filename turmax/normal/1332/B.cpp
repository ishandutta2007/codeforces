#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    vector <int> v={2,3,5,7,11,13,17,19,23,29,31};
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int res[n];
    vector <int> z;
    set <int> u;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        for(int j=0;j<11;++j)
        {
            if(x%v[j]==0)
            {
                res[i]=(j+1);
                break;
            }
        }
        if(!u.count(res[i]))
        {
            u.insert(res[i]);
            z.push_back(res[i]);
        }
    }
    sort(z.begin(),z.end());
    cout<<z.size()<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<(lower_bound(z.begin(),z.end(),res[i])-z.begin()+1)<<" ";
    }
    cout<<endl;
    }
    return 0;
}