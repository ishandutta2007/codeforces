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

long long a[26][26];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector<ll> cnt(26);
    for(char c:s) cnt[c-'a']++;
    long long ans = 0;
    for(int i=0;i<26;++i) {
        ans=max(ans,cnt[i]);
        ans=max(ans,cnt[i]*(cnt[i]-1)/2);
    }
    for(int i=0;i<26;++i) {
        for(int j=0;j<26;++j) {
            if(i == j) continue;
            ll tmp=0;
            for(char c:s) {
                if(c-'a' == i) tmp++;
                if(c-'a' == j) a[i][j] += tmp;
            }
            
        }
    }
    for(int i=0;i<26;++i)
        for(int j=0;j<26;++j)
            ans=max(ans,a[i][j]);
    cout<<ans<<endl;
}