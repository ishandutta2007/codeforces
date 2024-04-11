#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string uwu; cin >> uwu;
        int n; cin >> n;
        char ans[n+1]; int arr[n+1]={0},freq[26]={0}; bool vis[n+1]={0};
        for (char x:uwu) freq[x-'a']++;
        for (int i=1;i<=n;++i) cin >> arr[i];
        vector<int> zeroes;
        int idx=25;
        while (true){
            zeroes.clear();
            for (int i=1;i<=n;++i){
                if (arr[i]!=0||vis[i]) continue;
                zeroes.push_back(i);
                vis[i]=1;
            }
            while (zeroes.size()>freq[idx]) idx--;
            for (int x:zeroes) ans[x]=idx+'a';
            for (int i=1;i<=n;++i){
                for (int x:zeroes) arr[i]-=abs(x-i);
            }
            if (zeroes.empty()) break;
            idx--;
        }
        for (int i=1;i<=n;++i) cout << ans[i];
        cout << '\n';
    }
}