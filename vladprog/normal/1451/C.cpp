#include <bits/stdc++.h>

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
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        int cnta[26]={};
        for(char c:a)
            cnta[c-'a']++;
        int cntb[26]={};
        for(char c:b)
            cntb[c-'a']++;
        bool ok=true;
        for(int i=0;i<25;i++)
        {
            if(cnta[i]<cntb[i]||
               (cnta[i]-cntb[i])%k)
                ok=false;
            cnta[i+1]+=cnta[i]-cntb[i];
        }
        ok&=cnta[25]==cntb[25];
        cout<<(ok?"Yes\n":"No\n");
    }
}