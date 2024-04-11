#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> a(4);
        for(int i=0;i<4;++i) cin>>a[i];
        sort(a.begin(),a.end());
        int ans=0;
        do
        {
            int x=min(a[0],a[1]),y=min(a[2],a[3]);
            ans=max(ans, x*y);
        }while(next_permutation(a.begin(),a.end()));
        cout << ans << endl;
    }
}