#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vvi nb;
vi ans;
vi par;
bool done;
vvi ch;
int n,m;
void print() {
    printf("YES\n");
    forn(i,0,n) printf("%d ", ans[i]);
    printf("\n");
}
int st;
vi sts;

vi parc;
vi vis;

void dfscyc(int v, int p) {
    parc[v] = p;
    vis[v] = 1;
    for(auto u : nb[v]) {
        if(done) break;
        if (u == p) continue;
        if(vis[u]) {
            ans[u] = 1;
            ans[v] = 1;
            int cur = v;
            while(parc[cur] != u) {
                cur = parc[cur];
                ans[cur] = 1;
            }
            print();
            done = true;
            break;
        }
        dfscyc(u, v);
    }
}

void dfs(int v, int p) {
    par[v] = p;
    sts[v] = 1;
    for(auto u : nb[v]) {
        if(done) break;
        if(u==p) continue;
        if(nb[u].size() == 3) {
            for(auto x : nb[st]) ans[x] = 1;
            for(auto x : nb[u]) ans[x] = 1;
            ans[u] = 2;
            int cur = v;
            while(cur != st) {
                ans[cur] = 2;
                cur = par[cur];
            }
            ans[st] = 2;
            print();
            done = true;
            break;
        }
        ch[v].pb(u);
        dfs(u, v);
        sts[v] += sts[u];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(i,0,t) {
        
        scanf("%d %d", &n, &m);
        nb.clear();
        nb.resize(n);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--; v--;
            nb[u].pb(v);
            nb[v].pb(u);
        }
        done = false;
        ans = vi(n,0);
        sts = vi(n,0);
        ch.clear();
        ch.resize(n);
        par = vi(n,-1);
        forn(i,0,n) {
            if(nb[i].size() > 3) {
                ans[i] = 2;
                for(auto x : nb[i]) ans[x] = 1;
                done = true;
                print();
                break;
            }
        }
        vis = vi(n,0);
        parc = vi(n,-1);
        forn(i,0,n) {
            if(!vis[i]) dfscyc(i, -1);
        }
        if(done) continue;
        forn(i,0,n) {
            if(done) break;
            st = i;
            if(nb[i].size() == 3) {
                dfs(i, -1);
                if(done) break;
                vpi num;
                for(auto x : nb[i]) num.pb(mp(sts[x], x));
                sort(all(num));
                if(num[0].first>=2) {
                    ans[i] = 3;
                    ans[num[0].second] = 2;
                    ans[ch[num[0].second][0]] = 1;
                    ans[num[1].second] = 2;
                    ans[ch[num[1].second][0]] = 1;
                    ans[num[2].second] = 2;
                    ans[ch[num[2].second][0]] = 1;
                    print();
                    done = true;
                    break;
                }
                else if(num[0].first == 1) {
                    if(num[1].first == 1) {
                        continue;
                    }
                    else if(num[1].first >= 3) {
                        ans[i] = 4;
                        ans[num[0].second] = 2;
                        forn(j,1,3) {
                            int v = num[j].second;
                            ans[v] = 3;
                            ans[ch[v][0]] = 2;
                            ans[ch[ch[v][0]][0]] = 1;
                        }
                        print();
                        done = true;
                        break;
                    }
                    else if(num[1].first == 2){
                        if(num[2].first >= 5) {
                            ans[i] = 6;
                            ans[num[0].second] = 3;
                            ans[num[1].second] = 4;
                            ans[ch[num[1].second][0]] = 2;
                            int v = num[2].second;
                            int cur = 5;
                            while(cur > 0) {
                                ans[v] = cur;
                                cur--;
                                if(cur>0) v = ch[v][0];
                            }
                            print();
                            done = true;
                            break;
                        }
                        else continue;
                    }
                }
            }
        }
        if(done) continue;
        printf("NO\n");
    }
    
}