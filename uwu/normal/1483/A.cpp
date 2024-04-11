#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int force[MAXN], cnt[MAXN];
vector<int> day[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        for (int i=1;i<=n;++i) force[i]=cnt[i]=0;
        for (int i=1;i<=m;++i) day[i].clear();
        for (int i=1;i<=m;++i){
            int cnt; cin >> cnt;
            for (int j=1;j<=cnt;++j){
                int x; cin >> x;
                day[i].push_back(x);
            }
            if (cnt==1) force[day[i][0]]++;
        }
        if (*max_element(force+1,force+1+n)>(m+1)/2){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i=1;i<=m;++i){
            if (day[i].size()==1) force[day[i][0]]--;
            for (int x:day[i]){
                if (cnt[x]+1+force[x]>(m+1)/2) continue;
                cout << x << " ";
                cnt[x]++; break;
            }
        }
        cout << '\n';
    }
}