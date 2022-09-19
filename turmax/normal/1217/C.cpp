#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int po[40];
    int u=1;
    for(int i=0;i<40;++i)
    {
        po[i]=u;
        u*=2;
    }
    int t;
    cin>>t;
    string s;
    vector <int> a;
    vector <int> v;
    int x;
    int y;
    vector <int> l;
    int sum;
    int r;
    for(int i=0;i<t;++i)
    {
        r=0;
        v.clear();
        cin>>s;
        a.resize(s.size());
        for(int i=0;i<s.size();++i)
        {
            a[i]=(s[i]-'0');
            if(a[i]==1)
            {
                v.push_back(i);
            }
        }
        for(int j=0;j<s.size();++j)
        {
            l.clear();
            x=(lower_bound(v.begin(),v.end(),j-30)-v.begin());
            x--;
            if(x==(-1))
            {
                y=j+1;
            }
            else
            {
                y=(j-v[x]);
            }
            sum=0;
            for(int k=j;k>=max(0LL,j-30);--k)
            {
                if(a[k]==1)
                {
                    sum+=po[j-k];
                }
                if(sum==(j-k+1))
                        {
                            ++r;
                        }
            }
            if((sum<=y) && 31<sum)
            {
                ++r;
            }
        }
        cout<<r<<endl;
    }
    return 0;
}