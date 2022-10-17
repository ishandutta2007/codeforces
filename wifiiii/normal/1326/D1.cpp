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
const ull m = 1395293482ull;
const int maxn = 5005;
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
//    cout << (lh[j]+rh[j+1]*pw[j-i+1])%m << " " <<  (rh[i]+lh[i-1]*pw[j-i+1])%m << endl;
    return (lh[j]+rh[j+1]*pw[j-i+1])%m == (rh[i]+lh[i-1]*pw[j-i+1])%m;
}
int f[5005][5005];
int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        init(s);
        for(int i=0;i<s.size();++i)
            for(int j=i;j<s.size();++j)
                f[i][j] = ispal(i,j);
        int ans = 0;
        string anss;
        for(int len=0;len<=s.size()/2;++len)
        {
            string pre=s.substr(0,len),suf=s.substr(s.size()-len,len);
            for(int i=len;i<s.size()-len;++i) {
                if(f[len][i] && len+i+1>ans) ans=len+i+1,anss=pre+s.substr(len,i-len+1)+suf;
            }
            if(s[len] != s[s.size()-len-1]) break;
        }
        reverse(s.begin(),s.end());
        init(s);
        for(int i=0;i<s.size();++i)
            for(int j=i;j<s.size();++j)
                f[i][j] = ispal(i,j);
        for(int len=0;len<=s.size()/2;++len)
        {
            string pre=s.substr(0,len),suf=s.substr(s.size()-len,len);
            for(int i=len;i<s.size()-len;++i) {
                if(f[len][i] && len+i+1>ans) ans=len+i+1,anss=pre+s.substr(len,i-len+1)+suf;
            }
            if(s[len] != s[s.size()-len-1]) break;
        }
        cout << anss << endl;
    }
}