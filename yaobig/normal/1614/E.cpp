#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
template <typename A, typename B> string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}
template <typename A> string to_string(A v) 
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {cerr << endl;} 
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) 
{
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200100;
const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using rank_tree = tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    int n; scanf("%d",&n);
    rank_tree T;
    int off = 0;
    auto ask = [&](int x) {
        return x + off - (int)T.order_of_key(x+1);
    };
    auto kth = [&](int x) {
        x -= off;
        int l = -maxn, r = maxn + 1000000000;
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(mid-(int)T.order_of_key(mid+1)>=x) r=mid;
            else l=mid+1;
        }
        return l;
    };
    int lastans = 0;
    rep(i,1,n)
    {
        int t; scanf("%d",&t);
        int x = kth(t), y = kth(t+1);
        T.insert(x); T.insert(y); off++;
        int k; scanf("%d",&k); 
        while(k--)
        {
            int x; scanf("%d",&x); x = (x+lastans)%1000000001;
            int ans = ask(x);
            printf("%d\n",ans);
            lastans = ans;
        }
    }

    return 0;
}