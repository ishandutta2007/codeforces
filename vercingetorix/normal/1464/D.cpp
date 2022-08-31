#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
const int N = 100500;
int parent[N];
int rk[N];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(p, n);
        forn(i,0,n) p[i]--;
        vi vis(n,0);
        vvi cyc(3);
        forn(i,0,n) {
            if(vis[i] == 0) {
                int cur = i;
                int num = 1;
                vis[cur] = 1;
                while(!vis[p[cur]]) {
                    cur = p[cur];
                    vis[cur] = 1;
                    num++;
                }
                cyc[num%3].pb(num);
            }
        }
        ll ans = 1;
        int m = n;
        while(m > 4) {
            ans = ans*3%mod;
            m-=3;
        }
        ans = ans*m%mod;
        int step = 0;
        
        for(auto x : cyc[0]) step += x/3-1;
        srtrev(cyc[1]);
        if(n%3 == 1) {
            if(!cyc[1].empty() && cyc[1][0] >= 4 && cyc[1].size() > cyc[2].size()) {
                swap(cyc[1][0], cyc[1].back());
                while(cyc[1].back() > 4) {
                    step++;
                    cyc[1].back() -= 3;
                }
                cyc[1].pop_back();
            }
            else if(cyc[2].size() > 1) {
                forn(adda,0,2) {
                    step+=cyc[2].back()/3;
                    cyc[2].pop_back();
                }
            }
            else if(cyc[2].size() == 1) {
                forn(adda,0,2) {
                    step += cyc[1].back()/3;
                    cyc[1].pop_back();
                }
                step+=cyc[2].back()/3;
                cyc[2].pop_back();
                step+=1;
            }
            else if(cyc[1].size() >= 4) {
                forn(adda,0,4) {
                    step += cyc[1].back()/3;
                    cyc[1].pop_back();
                }
                step+=2;
            }
            else {
                step += 1;
            }
//            srtrev(cyc[1]);
        }
        while(cyc[1].size() >0 && cyc[2].size() > 0) {
            int x = cyc[1].back();
            int y = cyc[2].back();
            cyc[1].pop_back();
            cyc[2].pop_back();
            step += x/3+y/3+1;
        }
        if(cyc[2].size() > 0) {
            forn(i,0,cyc[2].size()) step += cyc[2][i] / 3;
            int k = cyc[2].size();
            while(k>=3) {
                k-=3;
                step += 3;
            }
        }
        if(cyc[1].size() > 0) {
            while(cyc[1].size() > 4 || cyc[1].size() == 3) {
                step+=2;
                forn(adad,0,3) {
                    step+=cyc[1].back()/3;
                    cyc[1].pop_back();
                }
            }
            int k = cyc[1].size();
            if(k == 2) {
                step += 1 + cyc[1][0] / 3 + cyc[1][1] / 3;
            }
            else if(k==4) {
                step+=2;
                if(cyc[1][0] >= 4) {
                    forn(adad,0,3) {
                        step+=cyc[1].back()/3;
                        cyc[1].pop_back();
                    }
                    while(cyc[1][0] > 4) {
                        cyc[1][0] -= 3;
                        step++;
                    }
                }
            }
        }
        cout<<ans<<' '<<step<<endl;
    }
    
}