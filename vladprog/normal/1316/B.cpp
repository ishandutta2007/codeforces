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
        int n;
        string s;
        cin>>n>>s;
        s="_"+s;
        pair<string,int> ans(string(1,'z'+1),n+1);
        for(int k=1;k<=n;k++)
        {
            pair<string,int> cur;
            cur.second=k;
            string lef=s.substr(k);
            string rig=s.substr(1,k-1);
            if((n-k)%2==0)
                reverse(rig.begin(),rig.end());
            cur.first=lef+rig;
            ans=min(ans,cur);
        }
        cout<<ans.first<<"\n"<<ans.second<<"\n";
    }
}