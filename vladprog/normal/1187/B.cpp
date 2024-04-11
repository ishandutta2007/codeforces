#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;

int pref[N][26];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    string s;
    cin>>n>>s>>m;
    for(int i=1;i<=n;i++)
        pref[i][s[i-1]-'a']=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            pref[i][j]+=pref[i-1][j];
    while(m--)
    {
        string t;
        cin>>t;
        int cnt[26]={};
        for(char c:t)
            cnt[c-'a']++;
        int l=0,r=n;
        while(l<r)
        {
            int k=(l+r)/2;
            bool ok=true;
            for(int i=0;i<26;i++)
                if(cnt[i]>pref[k][i])
                    ok=false;
            if(ok)
                r=k;
            else
                l=k+1;
        }
        cout<<l<<"\n";
    }
}