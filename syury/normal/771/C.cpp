#include<bits/stdc++.h>

using namespace std;

#define F(i, a, b) for(auto i = (a); i < (b); ++i)
#define f(i, n) F(i, 0, n)
#define re return
#define pb push_back
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

vector<int> v[250050];
ll was[200500], was2[200500], was3[200500];
ll lvl[205000];
ll cnt[200500][5];
ll onlvl[5];
ll n, k;
ll dd[200500][5];
ll pr[200500];
int dfs(int w, int cur){
    if(was[w]) re 0;
    was[w] = 1;
    lvl[w] = cur;
    //cout << k << endl;
    onlvl[cur%k]++;
    //cout << w << endl;
    cnt[w][0]++;
    //cout << w << endl;
    for(auto to : v[w]) if(dfs(to, cur+1)){
        f(i, k) cnt[w][(i+1)%k] += cnt[to][i];
        pr[to] = w;
    }
    return 1;
}
ll ans;
ll cur;
ll dfs2(int w, int curdist){
    //cout << w << ' ' << was2[w] << endl;
    if(was2[w]) re 0;
    was2[w] = 1;
    //cout << v[w].size() << ' ' << curdist << endl;
    cur+=(k-1+curdist)/k;
    for(auto to : v[w]){
        dfs2(to, curdist+1);
    }
    re 0;
}

ll dfs3(int w, ll dist){
    if(was3[w]) re 0;
    was3[w] = 1;
    if(w == 1){
        dist = cur;
    }
    else{
         f(i, k) dd[w][(i+1)%k] = dd[pr[w]][i] - cnt[w][(i+k-1)%k] + cnt[w][(i+1)%k];
         if(k == 1){
            dist += dd[pr[w]][0];
            dist -= 2*cnt[w][0];
         }
         else if(k == 2){
            dist += dd[pr[w]][0];
            dist -= cnt[w][0] + cnt[w][1];
         }
         else{
            dist += dd[pr[w]][0];
            dist -= cnt[w][k-1];
            dist -= cnt[w][0];
         }
    }
    ans+=dist;
    /*cout << w << ' ' << dist << endl;
    cout << "dd : ";
    f(i, k) cout << dd[w][i] << ' ';
    cout << " cnt : ";
    f(i, k) cout << cnt[w][i] << ' ';
    cout << endl;
    */for(auto to : v[w]) dfs3(to, dist);
    re 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin >> n >> k;
    f(i, n-1){
        ll a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    f(i, k) dd[1][i] = cnt[1][i];
    dfs3(1, 0);
    cout << ans/2;
}
/*
11 4
1 2
2 3
3 4
4 5
5 6
1 7
7 8
7 9
7 10
7 11
*/