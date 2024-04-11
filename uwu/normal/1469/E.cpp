#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

bool seen[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        string s; cin >> s; s=" "+s;
        for (int i=0;i<=n;++i) seen[i]=0;
        int cnt1=0;
        for (int i=1;i<=k-1;++i) cnt1+=s[i]=='0';
        for (int i=k;i<=n;++i){
            cnt1+=s[i]=='0';
            ll curr=0, left=cnt1;
            bool flag=1;
            for (int j=i;j>=i-k+1;--j){
                if (s[j]=='0') curr+=(1<<(i-j)), left--;
                if (curr>n||(1<<(i-j))>n){ flag=0; break; }
                if (left==0) break;
            }
            if (flag) seen[curr]=1;
            cnt1-=s[i-k+1]=='0';
        }
        int lim;
        if (k>=23) lim=n+1;
        else lim=(1<<k);
        for (int i=0;i<=n;++i){
            if (i>=lim){ cout << "NO" << '\n'; break; }
            if (seen[i]) continue;
            cout << "YES" << '\n';
            for (int j=k-1;j>=0;--j){
                if (j>=23) cout << 0;
                else cout << (1&(i>>j));
            }
            cout << '\n';
            break;
        }
    }    
}