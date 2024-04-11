
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)


int a[1000005],sum[1000005];
int main()
{
    string s,t;
    cin>>s>>t;
    for(int i=1;i<s.size();++i) if(s[i]!=s[i-1]) a[i]=1;
    for(int i=1;i<s.size();++i) sum[i]=sum[i-1]+a[i];
    //for(int i=1;i<=s.size();++i) cout<<sum[i]<<" ";cout<<endl;
    int p = 0;
    for(int i=0;i<t.size();++i) if(s[i]!=t[i]) p++;
    p = p % 2;
    int ans = 0;
    if(!p) ans++;
    int i = t.size();
    while(i<s.size())
    {
        //cout << i << " " << i-t.size() << endl;
        p += sum[i] - sum[i-t.size()];
        p = p % 2;
        if(!p) ans++;
        i++;
    }
    cout<<ans<<endl;
}