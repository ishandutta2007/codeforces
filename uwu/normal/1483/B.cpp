#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

vector<int> ans;
queue<int> q;
map<int,int> m;

int lastval(int i){
    if (m.find(i)==m.begin()) return (--m.end())->second;
    else return (--m.find(i))->second;
}

int nextidx(int i){
    if (++m.find(i)==m.end()) return m.begin()->first;
    return (++m.find(i))->first;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i){
            int x; cin >> x;
            m[i]=x;
        }
        for (int i=2;i<=n;++i) q.push(i);
        q.push(1);
        while (!q.empty()){
            int idx=q.front(); q.pop();
            int v=m[idx];
            if (gcd(v,lastval(idx))==1){
                ans.push_back(idx);
                if (m.size()!=1){
                    int nxt=nextidx(idx);
                    if (!q.empty()&&q.front()==nxt) q.pop();
                    q.push(nxt);
                }
                m.erase(idx);
            }
        }
        cout << ans.size() << " ";
        for (int x:ans) cout << x << " ";
        cout << '\n';
        m.clear();
        ans.clear();
        while (!q.empty()) q.pop();
    }
}