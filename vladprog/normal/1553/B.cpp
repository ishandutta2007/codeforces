#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

bool solve()
{
    string s,t;
    cin>>s>>t;
    int n=s.size(),k=t.size();
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            string res=s.substr(i,j-i+1);
            for(int q=j-1;q>=0&&res.size()<k;q--)
                res+=s[q];
            if(res==t)
                return true;
        }
    return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<(solve()?"YES\n":"NO\n");
}