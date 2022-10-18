#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<string> s;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        string t=a+b[1]+b[0];
        string srt[4];
        srt[0]=t;
        for(int i=1;i<4;i++)
            srt[i]=srt[i-1].substr(1)+srt[i-1][0];
        sort(srt,srt+4);
        s.insert(srt[0]);
        if(n) cin>>a;
    }
    cout<<s.size();
}