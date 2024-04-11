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

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        sort(s.begin(),s.end());
        s="_"+s;
        if(s[1]!=s[k]||n==k)
            cout<<s[k]<<"\n";
        else if(s[k+1]==s[n])
        {
            int cnt=(n-k+k-1)/k;
            cout<<s[1]<<string(cnt,s[n])<<"\n";
        }
        else
            cout<<s.substr(k)<<"\n";
    }
}