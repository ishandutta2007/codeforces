#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[200005][27],cnt[27];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int j=1;j<=n;++j)
        for(int i=0;i<=26;++i) a[j][i]=n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();++i) {
        cnt[s[i]-'a']++;
        a[cnt[s[i]-'a']][s[i]-'a']=i;
    }
    int m;
    cin>>m;
    while(m--)
    {
        string t;
        cin>>t;
        int ans=0;
        int cnt[27]={0};
        for(int i=0;i<t.size();++i) cnt[t[i]-'a']++;
        for(int i=0;i<26;++i) ans=max(ans,a[cnt[i]][i]);
        cout<<ans+1<<"\n";
    }
}