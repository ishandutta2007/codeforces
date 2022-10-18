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
        string s;
        cin>>s;
        int mx=0,cur=0;
        for(char c:s)
            if(c=='L')
                mx=max(mx,++cur);
            else
                cur=0;
        cout<<mx+1<<"\n";
    }
}