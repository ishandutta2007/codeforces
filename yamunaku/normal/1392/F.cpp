//
// Created by yamunaku on 2020/08/16.
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

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

int main(){
    int n;
    scanf("%d", &n);
    vl h(n);
    rep(i, n) scanf("%lld", &h[i]);
    rep(i, n) h[i] -= i;

    struct pa{
        ll h;
        ll w;
        ll a;
    };
    stack<pa> st;
    rep(i, n){
        ll sum = h[i];
        ll sumw = 1;
        while(!st.empty()){
            auto p = st.top();
            if(sum / sumw >= p.h){
                st.pop();
                sum += p.h * p.w + p.a;
                sumw += p.w;
            }else{
                break;
            }
        }
        st.push({sum / sumw, sumw, sum % sumw});
    }
    int idx = 0;
    while(!st.empty()){
        auto p = st.top();
        st.pop();
        rep(i, p.w){
            h[idx] = p.h;
            if(i < p.a) h[idx]++;
            idx++;
        }
    }
    rep(i, n) h[i] += i;
    rep(i, n) printf("%lld ", h[i]);
    printf("\n");
    return 0;
}