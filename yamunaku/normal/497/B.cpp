//
// Created by yamunaku on 2019/08/13.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

int main(){
    CFS;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sz = 1, tmp = 1;
    while(tmp < n) sz++, tmp *= 2;
    vector<vector<int>> nx1(n + 2, vector<int>(sz));
    vector<vector<int>> nx2(n + 2, vector<int>(sz));
    nx1[n][0] = nx1[n + 1][0] = n + 1, nx2[n][0] = nx2[n + 1][0] = n + 1;
    int xx = n + 1, yy = n + 1;
    per(i, n){
        if(a[i] == 1) xx = i + 1;
        else yy = i + 1;
        nx1[i][0] = xx;
        nx2[i][0] = yy;
    }
    repl(i,1,sz){
        rep(j,n+2){
            nx1[j][i]=nx1[nx1[j][i-1]][i-1];
            nx2[j][i]=nx2[nx2[j][i-1]][i-1];
        }
    }
    vector<pair<int, int>> ans;
    repl(i, 1, n + 1){
        int one = 0, two = 0;
        bool ok = true;
        int idx1 = 0, idx2 = 0;
        int win=-1;
        while(1){
            int tmp = i, x = 0;
            while(tmp){
                if(tmp & 1){
                    idx1 = nx1[idx1][x];
                    idx2 = nx2[idx2][x];
                }
                tmp >>= 1;
                x++;
            }
            if(idx1 == n + 1 && idx2 == n + 1){
                ok = false;
                break;
            }
            if(idx1 < idx2){
                one++;
                idx2 = idx1;
                win=1;
            }else{
                two++;
                idx1 = idx2;
                win=2;
            }
            if(idx1 == n){
                break;
            }
        }
        if(ok){
            if(one>two){
                if(win==1){
                    ans.push_back({max(one, two), i});
                }
            }else if(one<two){
                if(win==2){
                    ans.push_back({max(one, two), i});
                }
            }
        }
    }
    int s = ans.size();
    cout << ans.size() << endl;
    sort(all(ans));
    rep(i, s){
        cout << ans[i].first SP ans[i].second << endl;
    }
    return 0;
}