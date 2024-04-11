#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=15;

int n,m;
string a[N];

bool check(string s)
{
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
            cnt+=a[i][j]!=s[j];
        if(cnt>1)
            return false;
    }
    return true;
}

string solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(check(a[0]))
        return a[0];
    for(int i=0;i<m;i++)
        for(char c='a';c<='z';c++)
        {
            string s=a[0];
            s[i]=c;
            if(check(s))
                return s;
        }
    return "-1";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
}