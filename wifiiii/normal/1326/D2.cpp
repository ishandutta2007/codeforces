#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

typedef unsigned long long ull;
const ull p = 43;
const ull m = 1395293481ull;
const int maxn = 1000005;
ull pw[maxn],lh[maxn];
ull rh[maxn];
void init(string s)
{
    int n=s.size();
    pw[0]=1,lh[0]=rh[n+1]=0;
    for(int i=1;i<=n;++i) pw[i]=pw[i-1]*p%m;
    for(int i=1;i<=n;++i) lh[i]=(lh[i-1]*p+s[i-1])%m;
    for(int i=n;i>=1;--i) rh[i]=(rh[i+1]*p+s[i-1])%m;
}
bool ispal(int i,int j) {
    ++i, ++j;
    return (lh[j]+rh[j+1]*pw[j-i+1])%m == (rh[i]+lh[i-1]*pw[j-i+1])%m;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int i = 0, j = s.size()-1;
        while(i<j && s[i]==s[j]) ++i, --j;
        init(s);
        string pre = s.substr(0, i);
        string suf = s.substr(j+1, i);
        string ans1=pre+suf,ans2=pre+suf;
        for(int k=j;k>=i;--k) if(ispal(i,k)) {ans1=pre+s.substr(i,k-i+1)+suf;break;}
        for(int k=i;k<=j;++k) if(ispal(k,j)) {ans2=pre+s.substr(k,j-k+1)+suf;break;}
        if(ans1.size() > ans2.size()) cout << ans1 << endl;
        else cout << ans2 << endl;
    }
}