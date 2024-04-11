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
        string s;
        cin>>s;
        int ans=0;
        for(char a='0';a<='9';a++)
            for(char b='0';b<='9';b++)
            {
                int last=-1,res=0;
                for(char c:s)
                    if(c==a&&last!=0)
                        res++,last=0;
                    else if(c==b&&last!=1)
                        res++,last=1;
                ans=max(ans,res/2*2);
                if(a==b)
                    ans=max(ans,res);
            }
        cout<<s.size()-ans<<"\n";
    }
}