#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        string s[n];
        for(int i=0;i<n;++i) cin>>s[i];
        bool used[n][m];for(int i=0;i<n;++i) for(int j=0;j<m;++j) used[i][j]=false;
        for(int i=(n-1);i>=k;i--)
        {
            for(int j=k;j<(m-k);++j)
            {
                if(s[i][j]=='.') continue;
                bool ok1=true;
                for(int l=0;l<k;++l)
                {
                    ok1=(ok1 && s[i-l-1][j-l-1]=='*' && s[i-l-1][j+l+1]=='*');
                }
                if(!ok1) continue;
                used[i][j]=true;
                for(int l=0;l<k;++l)
                {
                    used[i-l-1][j-l-1]=true;used[i-l-1][j+l+1]=true;
                }
                for(int l=k;;++l)
                {
                    if((i-l-1)<0 || (j-l-1)<0 || (j+l+1)>=m || s[i-l-1][j-l-1]=='.' || s[i-l-1][j+l+1]=='.') break;
                    used[i-l-1][j-l-1]=true;used[i-l-1][j+l+1]=true;
                }
            }
        }
        bool ok=true;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j)
        {
        if(s[i][j]=='*' && !used[i][j])
        {
            ok=false;
        }
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}