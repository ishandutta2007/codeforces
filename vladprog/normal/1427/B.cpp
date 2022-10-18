#include <bits/stdc++.h>

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
        string s;
        cin>>n>>k>>s;
        int cur=0;
        bool prv=false;
        for(char c:s)
            if(c=='W')
                cur+=(prv?2:1),
                prv=true;
            else
                prv=false;
        if(cur==0)
        {
            cout<<max(0ll,2*k-1)<<"\n";
            continue;
        }
        int l=0;
        while(l<n&&s[l]=='L')
            l++;
        int r=0;
        vector<int> v;
        for(int i=l;i<n;i++)
            if(s[i]=='L')
                r++;
            else if(r)
                v.push_back(r),
                r=0;
        sort(v.begin(),v.end());
        for(int x:v)
            if(k>=x)
                cur+=2*x+1,
                k-=x;
            else
                cur+=2*k,
                k=0;
        cur+=2*min(l+r,k);
        cout<<cur<<"\n";
    }
}