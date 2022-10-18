#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int l=2,r=n;
        while(l<r)
        {
            int m=(l+r+1)/2;
            int cur=(1+m-2)*(m-2)/2+1;
            if(cur>k)
                r=m-1;
            else
                l=m;
        }
        int m=(l+r+1)/2;
        k-=(1+m-2)*(m-2)/2;
        string ans(n,'a');
        ans="_"+ans;
        ans[m]='b';
        ans[k]='b';
        ans=ans.substr(1);
        reverse(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
}