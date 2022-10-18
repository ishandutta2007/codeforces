#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int INF=1e18;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        for(int i=0;i<n;i++)
            s[i]-='a',
            t[i]-='a';
        int pos[26]={};
        for(int i=0;i<26;i++)
            while(pos[i]<n&&s[pos[i]]!=i)
                pos[i]++;
        int dist[26];
        for(int i=0;i<26;i++)
            dist[i]=pos[i];
        int ans=INF,res=0;
        for(int i=0;i<n;i++)
        {
            char ch=t[i];
//            cout<<i<<" -> "<<int(ch)<<" -> "<<pos[0]<<dist[0]<<" "<<pos[2]<<dist[2]<<"\n";
            for(int j=0;j<ch;j++)
                if(pos[j]!=n)
                    ans=min(ans,res+dist[j]);
            if(pos[ch]==n)
                break;
            int cur=pos[ch];
            res+=dist[ch];
            for(int j=0;j<26;j++)
                if(pos[j]>cur)
                    dist[j]--;
            s[cur]='?';
            while(pos[ch]<n&&s[pos[ch]]!=ch)
                dist[ch]+=s[pos[ch]]!='?',
                pos[ch]++;
        }
        cout<<(ans!=INF?ans:-1)<<"\n";
    }
}