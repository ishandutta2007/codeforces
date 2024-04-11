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

    int n;
    string s;
    cin>>n>>s;
    if(count(s.begin(),s.end(),'(')!=
       count(s.begin(),s.end(),')'))
        cout<<-1,exit(0);
    int ans=0,d=0;
    bool ok=true;
    for(char c:s)
    {
        if(c=='(')
            d++;
        else
            d--;
        if(!ok||d<0)
            ans++;
        ok=d>=0;
    }
    cout<<ans;
}