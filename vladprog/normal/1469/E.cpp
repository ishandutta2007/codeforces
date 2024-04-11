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

    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        for(char&c:s)
            c=(c=='0'?'1':'0');
        int x=max(0ll,k-20),y=min(k,20ll);
        set<string> all;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur>=x)
                all.insert(s.substr(i,y));
            if(s[i]=='0')
                cur++;
            else
                cur=0;
        }
        string ans="NO";
        for(int i=0;i<(1<<y);i++)
        {
            string cur=bitset<20>(i).to_string().substr(20-y);
            if(!all.count(cur))
            {
                ans="YES\n"+string(x,'0')+cur;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}