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
        string s;
        cin>>s;
        int k=count(s.begin(),s.end(),'0');
        int l=0;
        for(char c:s)
            if(c=='0')
                l++;
            else
                break;
        reverse(s.begin(),s.end());
        int r=0;
        for(char c:s)
            if(c=='0')
                r++;
            else
                break;
        cout<<max(0ll,k-l-r)<<"\n";
    }
}