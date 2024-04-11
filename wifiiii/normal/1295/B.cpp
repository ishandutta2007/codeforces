#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005];
int syn(int x) {if(!x) return 0;return x>0?1:-1;}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        int c1=0,c0=0;
        for(char c:s)if(c=='0') c0++;else c1++;
        for(int i=1;i<=s.size();++i) {
            if(s[i-1] == '1') a[i] = a[i-1] - 1;
            else a[i] = a[i-1] + 1;
        }
        int p = c0 - c1;
        int f = 0, ans = 0;
        if(x==0) ans++;
        for(int i=1;i<=s.size();++i) {
            int tmp = x - a[i];
            if(p == 0) {
                if(tmp == 0) {
                    f = 1;
                    break;
                }
            } else {
                if(syn(tmp) * syn(p) >= 0 && tmp % p == 0) ans++;
            }
        }
        if(f) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}