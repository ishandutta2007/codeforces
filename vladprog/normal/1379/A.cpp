#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const string NEED="abacaba";

string solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<=n-7;i++)
    {
        string t=s;
        bool ok=true;
        for(int j=0;j<7;j++)
            if(t[i+j]==NEED[j]||t[i+j]=='?')
                t[i+j]=NEED[j];
            else
                ok=false;
        if(!ok)
            continue;
        for(char&c:t)
            if(c=='?')
                c='z';
        int cnt=0;
        for(int j=0;j<=n-7;j++)
            if(t.substr(j,7)==NEED)
                cnt++;
        if(cnt==1)
            return "YES\n"+t;
    }
    return "No";
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