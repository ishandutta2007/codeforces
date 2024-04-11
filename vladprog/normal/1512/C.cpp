#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

string solve()
{
    int a,b;
    string s;
    cin>>a>>b>>s;
    int n=a+b;
    for(int i=0;i<s.size();i++)
        if(s[i]=='1'&&s[n-1-i]=='0')
            return "-1";
    for(int i=0;i<s.size();i++)
        if(s[i]=='?')
            s[i]=s[n-1-i];
    if(n%2&&s[n/2]=='?')
        if(a%2)
            s[n/2]='0';
        else
            s[n/2]='1';
    for(char c:s)
        if(c=='0')
            a--;
        else if(c=='1')
            b--;
    if(a%2||b%2||a<0||b<0)
        return "-1";
    for(int i=0;i<s.size();i++)
        if(s[i]=='?')
            if(a)
                s[i]=s[n-1-i]='0',a-=2;
            else
                s[i]=s[n-1-i]='1',b-=2;
    return s;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}