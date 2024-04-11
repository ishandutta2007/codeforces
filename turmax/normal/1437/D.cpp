#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        deque <int> q;
        q.push_back(1);
        deque <int> q1;
        int curr=(-1);
        int d=0;
        for(int i=1;i<n;++i)
        {
            if(q.empty())
            {
                ++d;
                q=q1;
                q1.clear();
            }
            int x=q.front();
            if(a[i]<curr)
            {
               q.pop_back();
               curr=(-1);
               --i;
            }
            else
            {
                curr=a[i];
                q1.push_back(curr);
            }
        }
        cout<<(d+1)<<endl;
    }
    return 0;
}