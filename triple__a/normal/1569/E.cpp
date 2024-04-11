#include<bits/stdc++.h>
#define int long long
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod=998244353;
const int inf=LLONG_MAX/4;
mt19937 rng(time(NULL)); // don't hack, pls!


const int maxn=100007;
const double EPS=1e-9;
const double pi=3.14159265358979;
int k,A,h;
unordered_map<int,int> s1,s2;
int a[maxn],ans[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.precision(20);
    cin>>k>>A>>h;
    a[0]=1;
    for (int i=1;i<=50;++i) a[i]=a[i-1]*A%mod;
    auto solve=[&](int offset,int win,int mask){
        int idx=0,hash=0;
        queue<int> q;
        while (sz(q)) q.pop();
        rep(i,1<<k-1) q.push(offset+i+1);
        for (int r=k-2;r>-1;--r){
            int mem=sz(q);
            rep(i,mem/2){
                int u=q.front();
                q.pop();
                int v=q.front();
                q.pop();
                if (mask>>idx&1) q.push(v), hash=(hash+u*a[(1<<r+1)+1])%mod;
                else q.push(u), hash=(hash+v*a[(1<<r+1)+1])%mod;
                idx++;
            }
        }
        assert(idx+1==1<<k-1);
        if (win) hash=(hash+q.front()*a[1])%mod;
        else hash=(hash+q.front()*a[2])%mod;
        return hash;
    };

    auto print=[&](int offset,int win,int mask){
        int idx=0;
        queue<int> q;
        while (sz(q)) q.pop();
        rep(i,1<<k-1) q.push(offset+i+1);
        for (int r=k-2;r>-1;--r){
            int mem=sz(q);
            rep(i,mem/2){
                int u=q.front();
                q.pop();
                int v=q.front();
                q.pop();
                if (mask>>idx&1) q.push(v), ans[u]=(1<<r+1)+1;
                else q.push(u), ans[v]=(1<<r+1)+1;
                idx++;
            }
        }
        if (win) ans[q.front()]=1;
        else ans[q.front()]=2;
    };
    rep(mask,1<<((1<<k-1)-1)) s1[solve(0,0,mask)]=mask+1;
    rep(mask,1<<((1<<k-1)-1)) s2[solve(1<<k-1,1,mask)]=mask+1;
    for (auto [u,v]:s1){
        if (s2[(h-u+mod)%mod]){
            int mask1=v-1, mask2=s2[(h-u+mod)%mod]-1;
            print(0,0,mask1);
            print(1<<k-1,1,mask2);
            rep1(i,1<<k) cout<<ans[i]<<" ";
            return 0;
        }
    }
    s1.clear(), s2.clear();
    rep(mask,1<<((1<<k-1)-1)) s1[solve(0,1,mask)]=mask+1;
    rep(mask,1<<((1<<k-1)-1)) s2[solve(1<<k-1,0,mask)]=mask+1;
    for (auto [u,v]:s1){
        if (s2[(h-u+mod)%mod]){
            int mask1=v-1, mask2=s2[(h-u+mod)%mod]-1;
            print(0,1,mask1);
            print(1<<k-1,0,mask2);
            rep1(i,1<<k) cout<<ans[i]<<" ";
            return 0;
        }
    }
    cout<<-1;
    return 0;
}

/*
2
101919804931827191 136638622643121931

*/