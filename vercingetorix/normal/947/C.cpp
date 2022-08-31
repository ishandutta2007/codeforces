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
struct node {
    int ch[2];
    int cnt;
    node() {
        ch[0] = -1;
        ch[1] = -1;
        cnt = 0;
    }
    void add(int bit, int x);
    void proc(int bit, int x);
};
int num = 1;
const int MAXN = 300500;


node v[MAXN*30];
void node::add(int bit, int x) {
    cnt++;
    if(bit == -1) {
        return;
    }
    int to = 0;
    if((1<<bit)&x) {
        x ^= (1<<bit);
        to = 1;
    }
    if(ch[to] == -1) {
        ch[to] = num++;
    }
    v[ch[to]].add(bit - 1, x);
}

void node::proc(int bit, int x) {
    cnt--;
    if(bit == -1) {
        printf("%d ", x);
        return;
    }
    int to = 0;
    if((1<<bit)&x) {
        x ^= (1<<bit);
        to = 1;
    }
    if(ch[to] == -1 || v[ch[to]].cnt == 0) {
        ch[to] = -1;
        to = 1-to;
        x |= 1<<bit;
    }
    v[ch[to]].proc(bit-1, x);
    
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    readv(p,n);
    for(auto x : p) v[0].add(29, x);
    for(auto x : a) v[0].proc(29, x);
    
    
}