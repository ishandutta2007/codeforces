#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=5e7+1;
bool is[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> v;
    if(n>=2000) v={2,3,5,7,11};
    else if(n>=300) v={2,3,5,7};
    else if(n>=60) v={2,3,5};
    else v={2,3};
    vector <int> g;
    is[1]=true;
    for(int i=1;i<=2*n*n;++i)
    {
        if(is[i])
        {
            g.push_back(i);
            for(auto u:v)
            {
                if((u*i)<maxn)
                {
                    is[u*i]=true;
                }
            }
        }
    }
    reverse(g.begin(),g.end());
    while(g.size()!=n) g.pop_back();
    for(auto v:g)
    {
        cout<<v<<" ";
    }
    return 0;
}