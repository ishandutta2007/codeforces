
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        string s,t;
        cin>>s>>t;
        reverse(all(t)),reverse(all(s));
        int p=0;
        for(int i=0;i<t.size();++i) if(t[i]=='1') {p=i;break;}
        int ans=0;
        for(int i=p;i<s.size();++i)
        {
            if(s[i]=='1') break;
            ans++;
        }
        cout<<ans<<endl;
    }
}