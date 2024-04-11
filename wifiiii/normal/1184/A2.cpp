#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)


map<int,int> mp;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans=0;
    int f=1;
    for(int i=0;i<n;++i) if(s[i]=='1') {f=0;break;}
    if(f) {cout<<n<<endl;return 0;}
    for(int k=1;k<=n;++k)
    {
        int g=gcd(k,n);
        if(mp.count(g)) ans+=mp[g];
        else
        {
            int ok=1;
            for(int i=1;i<=k;++i)
            {
                int tmp=0;
                for(int j=i;j<=n;j+=k)
                {
                    if(s[j-1]=='1') ++tmp;
                }
                if(tmp&1) {ok=0;break;}
            }
            mp[g]=ok;
            ans+=mp[g];
        }
    }
    cout<<ans<<endl;
}