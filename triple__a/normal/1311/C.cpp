#include<bits/stdc++.h>
using namespace std;

const int maxn = 500007;
string s;
int n,m,t,cnt[maxn][27],ans[27];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>m>>s;
        for (int i = 1; i <= n;++i){
            for (int j = 0; j < 26;++j){
                cnt[i][j] = 0;
            }
        }
        for (int j = 0; j < 26;++j){
            ans[j] = 0;
        }
            for (int i = 0; i < n; ++i)
            {
                cnt[i + 1][s[i] - 'a']++;
                for (int j = 0; j < 26; ++j)
                {
                    cnt[i + 1][j] += cnt[i][j];
                }
            }
        for (int i = 1; i <= m;++i){
            int u;
            cin >> u;
            for (int j = 0; j < 26;++j){
                ans[j] += cnt[u][j];
            }
        }
        for (int j = 0; j < 26;++j){
            cout << ans[j]+cnt[n][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}