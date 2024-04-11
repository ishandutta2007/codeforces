#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    deque <int> a;
    int delay1=0;
    int delay2;
    int t;
    for(int i=0;i<m;++i)
    {
        cin>>t;
        a.push_back(t);
    }
    int ite=0;
    int u;
    int v;
    int v1;
    while(a.size()>0)
    {
        ++ite;
        delay2=delay1;
        u=a.front();
        v=(u-delay1-1)/k;
        while(a.size()>0)
        {
            u=a.front();
            v1=(u-delay1-1)/k;
            if(v==v1)
            {
                a.pop_front();
                delay2++;
            }
            else
            {
                break;
            }
        }
        delay1=delay2;
    }
    cout<<ite;
    return 0;
}