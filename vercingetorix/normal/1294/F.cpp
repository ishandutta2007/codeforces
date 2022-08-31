#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int N = 200500;
vi g[N];
pair<int, pi> fork[N];
pi snake[N];
int n;
int ans = 0;
int a,b,c;

void dfs(int v, int p) {
    pair<int, pi> forks[2];
    pi snakes[3];
    forks[0] = mp(0, mp(v,v));
    forks[1] = mp(0, mp(v,v));
    snakes[0] = mp(0, v);
    snakes[1] = mp(0, v);
    snakes[2] = mp(0, v);
    pi badsnake = mp(-1,-1);
    for(auto u : g[v]) {
        if(u==p)continue;
        dfs(u,v);
        if(fork[u] >= forks[0]) {
            forks[1] = forks[0];
            forks[0] = fork[u];
            badsnake = snake[u];
        }
        else if(fork[u] >= forks[1]) {
            forks[1] = fork[u];
        }
        if(snake[u] >= snakes[0]) {
            snakes[2] = snakes[1];
            snakes[1] = snakes[0];
            snakes[0] = snake[u];
        }
        else if(snake[u] >= snakes[1]) {
            snakes[2] = snakes[1];
            snakes[1] = snake[u];
        }
        else if(snake[u] >= snakes[2]) {
            snakes[2] = snake[u];
        }
    }
    cout<<"";
    forn(s,0,2) forn(f,0,2) {
        if(s+f == 2) continue;
        if(s+f==0 && snakes[0] == badsnake) continue;
        if(forks[s].first + snakes[f].first + 1 > ans) {
            ans = forks[s].first + snakes[f].first + 1;
            a = forks[s].second.first;
            b = forks[s].second.second;
            c = snakes[f].second;
        }
    }
    if(snakes[0].first + snakes[1].first + snakes[2].first + 1 > ans) {
        ans = snakes[0].first + snakes[1].first + snakes[2].first + 1;
        a = snakes[0].second;
        b = snakes[1].second;
        c = snakes[2].second;
    }
    snake[v] = mp(snakes[0].first+1, snakes[0].second);
    fork[v] = mp(forks[0].first+1, forks[0].second);
    if(snakes[0].first + snakes[1].first + 1 > fork[v].first) {
        fork[v] = mp(snakes[0].first + snakes[1].first + 1, mp(snakes[0].second, snakes[1].second));
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    
    printf("%d\n", ans-1);
    if(a==b || a == c) {
        a = 0;
        while(a == b || a ==c) a++;
    }
    if(b==c) {
        b = 0;
        while(b==c || b == a) b++;
    }
    
    printf("%d %d %d", a+1, b+1, c+1);
    
    
}