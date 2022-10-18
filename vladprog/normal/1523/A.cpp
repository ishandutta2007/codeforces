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
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        s="0"+s+"0";
        while(m--)
        {
            bool ch=false;
            string t=s;
            for(int i=1;i<=n;i++)
                if(s[i]=='0'&&((s[i-1]=='1')^(s[i+1]=='1')))
                    t[i]='1';
            if(s==t)
                break;
            s=t;
        }
        cout<<s.substr(1,n)<<"\n";
    }
}