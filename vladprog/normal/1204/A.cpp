#pragma GCC optimize("O3")
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

    string s;
    cin>>s;
    int ans=0;
    for(string t="1";t.size()<=s.size();t+="00")
        if(t.size()<s.size()||t.size()==s.size()&&t<s)
        ans++;
    cout<<ans;
}