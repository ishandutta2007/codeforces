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
template <typename A, typename B> 
string to_string(pair<A, B> p) {return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")";}

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
using LL = __int128;
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200000;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;

char s[20];

int main()
{
    int cas; scanf("%d",&cas); while(cas--)
    {
        int x = 1,y = 1;
        auto output = [&]() {
            printf("%d %d\n",x,y); fflush(stdout);
            scanf("%s",s);
        };
        auto is_done = [&]() {return strcmp(s,"Done")==0;};
        auto is_up = [&]() {return s[0]=='U';};
        auto is_down = [&]() {return strcmp(s,"Done")!=0 && s[0]=='D';};
        auto chase = [&]() {
            do
            {
                x++; output();
                if(is_done()) return 1;  
            } while(is_down());
            return 0;
        };
        auto sweep = [&](){
            if(y!=1) 
            {
                y = 1; output();
                if(is_done()) return 1;
                if(is_down()) return chase();
            }
            int up = 0;
            while(y<8)
            {
                y++; output();
                if(is_done()) return 1;
                if(is_up()) up = 1;
                if(is_down()) return chase();
            }
            if(up==0) return chase();
            else return 0;
        };
        output();
        if(is_done()) continue;
        while(sweep()==0);
    }
    return 0;
}