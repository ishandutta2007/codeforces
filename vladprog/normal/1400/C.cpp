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
    string s;
    int x;
    cin>>s>>x;
    int n=s.size();
    string w(n,'_');
    for(int i=0;i<n;i++)
        if(s[i]=='0')
        {
            if(i-x>=0)
                if(w[i-x]=='1')
                    return "-1";
                else
                    w[i-x]='0';
            if(i+x<n)
                if(w[i+x]=='1')
                    return "-1";
                else
                    w[i+x]='0';
        }
        else
            if(i-x>=0&&w[i-x]!='0')
                w[i-x]='1';
            else if(i+x<n&&w[i+x]!='0')
                w[i+x]='1';
            else
                return "-1";
    for(char&c:w)
        if(c=='_')
            c='0';
    return w;
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