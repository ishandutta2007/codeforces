#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(x,idx) (1&(x>>idx))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=31;

int res[MAXN];

bool vis[1001];

bool slow(int a, int b){
    ms(vis,0);
    if (a>b) return 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(a);
    while (!pq.empty()){
        int v=pq.top(); pq.pop();
        if (v==b) return 1;
        if (v>b) return 0;
        for (int i=1;i<=v;++i){
            if ((v&i)==i&&!vis[v+i]) vis[v+i]=1, pq.push(v+i);
        }
    }
    return 0;
}

bool solve(){
    ms(res,0);
    int a, b; cin >> a >> b;
    //cout << (slow(a,b)?"YES":"NO") << " ";
    if (a>b) return 0;
    int ca=0, cb=0;
    for (int i=0;i<=30;++i){
        if (is(a,i)) ca++;
        if (is(b,i)) cb++;
        if (cb>ca) return 0;
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--){
        cout << (solve()?"YES":"NO") << '\n';
    }
}