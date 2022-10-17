#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define F(i,n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=0;i<n;++i)
#define ALL(i) i.begin(),i.end()

int cnt[200];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        memset(cnt,0,sizeof(cnt));
        string s,t,p;
        cin>>s>>t>>p;
        FF(i,p.size()) cnt[p[i]]++;
        int i=0,j=0,ok=0;
        while(1)
        {
            if(i<s.size() && s[i]==t[j]) i++,j++;
            else
            {
                if(cnt[t[j]]) cnt[t[j]]--,j++;
                else break;
            }
            if(j==t.size()) {ok=1;break;}
        }
        if(ok && i==s.size()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}