#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Data{
    char x; int n; bool fin, rev;
    Data(char x, int n, bool fin, bool rev) : x(x), n(n), fin(fin), rev(rev) {}
};

int main(){
    string S;
    cin >> S;
    int N = sz(S);
    int ans1[N];
    string ans2[N];
    deque<Data> deq;
    int cnt = 0;
    rep3(i, N-1, 0){
        if(!deq.empty() && deq[0].x == S[i] && !deq[0].fin){
            if(deq[0].rev) cnt--, deq.pop_front();
            else cnt++, deq[0].n++;
        }
        else{
            bool x = true;
            if(!deq.empty()){
                deq[0].fin = true;
                if(S[i] < deq[0].x) x = false;
                if(S[i] == deq[0].x) x = deq[0].rev;
            }
            cnt++, deq.emplace_front(S[i], 1, false, x);
        }
        ans1[i] = cnt;
        if(cnt <= 10){
            rep(j, sz(deq)){
                rep(k, deq[j].n) ans2[i] += deq[j].x;
            }
        }
        else{
            int n = 0;
            rep(j, sz(deq)){
                if(n == 5) break;
                rep(k, deq[j].n){
                    if(n == 5) break;
                    ans2[i] += deq[j].x, n++;
                }
            }
            n = 0;
            string tmp;
            rep3(j, sz(deq)-1, 0){
                if(n == 2) break;
                rep(k, deq[j].n){
                    if(n == 2) break;
                    tmp = deq[j].x+tmp, n++;
                }
            }
            ans2[i] += "..."+tmp;
        }
    }
    rep(i, N){
        cout << ans1[i] << ' ' << ans2[i] << endl;
    }
}