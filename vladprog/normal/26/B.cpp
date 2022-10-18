#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int ans=0,cnt=0;
    for(char c:s)
        if(c=='(')
            cnt++;
        else if(cnt)
            cnt--,ans++;
    cout<<ans*2;
}