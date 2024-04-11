#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin>>x;
    int u;
    int o;
    int n=0;
    vector <int> v;
    while(true)
    {
        if(x==1)
        {
            cout<<2*n<<endl;
            for(int i=0;i<v.size();++i)
            {
                cout<<v[i]<<" ";
            }
            return 0;
        }
        u=1;
        o=0;
        while(true)
        {
            u*=2;
            ++o;
            if(u==x)
            {
                v.push_back(o);
                cout<<2*n+1<<endl;
                for(int i=0;i<v.size();++i)
                {
                    cout<<v[i]<<" ";
                }
                return 0;
            }
            if(u>x)
            {
                v.push_back(o);
                x=(x^(u-1));
                ++x;
                break;
            }
        }
        ++n;
    }
    return 0;
}