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

    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    for(char c='z';c>='b';c--)
    {
        s+="_";
        string t;
        for(int i=0;i+1<s.size();i++)
        {
            char cur=s[i],nxt=s[i+1];
            t+=cur;
            while((t.size()>=1&&t[t.size()-1]==c)&&
                  (t.size()>=2&&t[t.size()-1]-1==t[t.size()-2]||
                   t.size()>=1&&t[t.size()-1]-1==nxt))
                t.pop_back(),
                ans++;
        }
        s=t;
    }
    cout<<ans;
}