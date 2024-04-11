#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s="codeforces";
    const int m=s.size();
    int a[m];
    for(int i=0;i<m;++i) a[i]=0;
    while(true)
    {
        int l=0;
        int mi=1e18;
        for(int i=0;i<m;++i)
        {
            if(a[i]<mi)
            {
                mi=a[i];
                l=i;
            }
        }
        a[l]++;
        int o=1;
        for(int i=0;i<m;++i)
        {
            o*=a[i];
        }
        if(o>=n)
        {
            for(int i=0;i<m;++i)
            {
                for(int j=0;j<a[i];++j)
                {
                    cout<<s[i];
                }
            }
            return 0;
        }
    }
    return 0;
}