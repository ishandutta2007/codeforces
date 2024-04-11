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
        cin>>n>>k;
        string s;
        cin>>s;
        int cnt[26]={};
        for(char c:s)
            cnt[c-'a']++;
        int ans=0;
        for(int l=1;l<=n;l++)
        {
            int g=__gcd(l,k);
            int d=l/g;
            int found=0;
            for(int c=0;c<26;c++)
                found+=cnt[c]/d;
            if(found>=g)
                ans=l;
        }
        cout<<ans<<"\n";
    }
}