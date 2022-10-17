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

string a[] = {"1110111", "0010010", "1011101", "1011011", "0111010",
    "1101011", "1101111", "1010010", "1111111", "1111011"};
int dis(string s,string t)
{
    int ret=0;
    for(int i=0;i<8;++i)
    {
        if(s[i] == '1' && t[i] == '0') ret++;
        else if(s[i] == '0' && t[i] == '1') return -1;
    }
    return ret;
}

int dp[2005][16005], d[2005][10];
string s[2005];
int ans[2005];
int main()
{
    int n,k;
    cin>>n>>k;
    ii cin>>s[i];
    for(int i=1;i<=n;++i) for(int j=0;j<10;++j) d[i][j]=dis(a[j],s[i]);
    dp[n+1][0] = 1;
//    for(int i=1;i<=n;++i) {for(int j=0;j<10;++j) cout<<d[i][j]<<" ";cout<<endl;}
    for(int i=n;i>=1;--i) {
        for(int j=0;j<=9;++j) {
            if(d[i][j] >= 0) {
                for(int k=(n+1-i)*7;k>=d[i][j];--k) {
                    dp[i][k] = max(dp[i][k], dp[i+1][k-d[i][j]]);
                }
            }
        }
    }
//    for(int i=1;i<=n;++i) {
//        for(int j=1;j<=k;++j)
//            cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    if(!dp[1][k]) return cout<<-1<<endl,0;
    for(int i=1;i<=n;++i) {
        for(int j=9;j>=0;--j) {
            if(d[i][j] >= 0) {
                if(k>=d[i][j] && dp[i+1][k-d[i][j]]) {
                    ans[i] = j;
                    k -= d[i][j];
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;++i) cout<<ans[i];cout<<endl;
}