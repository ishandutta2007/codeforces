#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

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
        map<int,int> m;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            m[x]++;
        }
        vector<int> a;
        for(auto p:m)
            a.push_back(p.second);
        sort(a.begin(),a.end(),greater<int>());
        for(int i=1;i<a.size();i++)
            if(a[i]>=a[i-1])
                a[i]=max(0ll,a[i-1]-1);
        cout<<accumulate(a.begin(),a.end(),0ll)<<"\n";
    }
}