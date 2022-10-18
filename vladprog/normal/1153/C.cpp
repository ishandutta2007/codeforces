#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    if(s[0]==')'||s[n-1]=='('||s.size()%2)
        cout<<":(",exit(0);
    s[0]='(';
    s[n-1]=')';
    /// s[1..n-2]
    int open=0,close=0;
    for(int i=1;i<=n-2;i++)
        if(s[i]=='(')
            open++;
        else if(s[i]==')')
            close++;
    int len=n-2;
    if(open>len/2||close>n/2)
        cout<<":(",exit(0);
    for(int i=1;i<=n-2;i++)
        if(s[i]=='?')
            if(open<len/2)
                s[i]='(',open++;
            else
                s[i]=')',close++;
    int d=0;
    for(int i=1;i<=n-2;i++)
    {
        if(s[i]=='(')
            d++;
        else
            d--;
        if(d<0)
            cout<<":(",exit(0);
    }
    cout<<s;
}