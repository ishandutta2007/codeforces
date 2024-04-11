#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=201;

int seen[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i=1;i<=2*n;++i) seen[i]=0;
        vector<pair<int,int>> chords;
        for (int i=1;i<=k;++i){
            int a, b; cin >> a >> b;
            if (a>b) swap(a,b);
            chords.push_back({a,b});
            seen[a]=1, seen[b]=1;
        }
        vector<int> left;
        for (int i=1;i<=2*n;++i){
            if (!seen[i]) left.push_back(i);
        }
        int x=left.size()/2;
        for (int i=0;i<x;++i){
            chords.push_back({left[i],left[i+x]});
        }
        int ans=0;
        for (int i=0;i<n;++i){
            for (int j=i+1;j<n;++j){
                auto [a,b]=chords[i];
                auto [c,d]=chords[j];
                if (b<d&&a>c) continue;
                if (d<b&&c>a) continue;
                if (b<c||d<a) continue;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}