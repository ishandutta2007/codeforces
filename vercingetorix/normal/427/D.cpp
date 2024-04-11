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
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int K =26;
struct vertex {
    int nextV = -1;
    char nextC;
    int* next = nullptr;
    //bool made=false;
    //bool leaf;
    char deg[2];
};

vector<vertex> t;
int sz;
void add_string (const string & s, int from, int ind) {
    int v = 0;
    for (size_t i=from; i<s.length(); ++i) {
        char c = s[i]-'a'; //    
        int newv;
        if(t[v].nextV == -1) {
            newv=sz;
            t[v].nextV = sz++;
            t[v].nextC = c;

            t.emplace_back();
        }
        else if(t[v].nextC==c) {
            newv=t[v].nextV;
        }
        else {
            if(t[v].next==nullptr) {
                t[v].next = new int[26];//= move(vi(26,-1));
                //memset (t[0].next, -1, sizeof t[0].next);
                 memset(t[v].next, 255, 26 * sizeof(int));
                //forn(ii,0,26) t[v].next[ii]=-1;
                t[v].next[t[v].nextC] = t[v].nextV;
               // t[v].made = true;
            }
            newv=t[v].next[c];
            if (newv == -1) {
                t.emplace_back();
                newv=sz;
                t[v].next[c] = sz++;

            }
            
        }
        v = newv;
        if(t[v].deg[ind]<2) t[v].deg[ind]++;
    }
    //t[v].leaf = true;
}
int bestl(int v) {
    if(t[v].deg[0]==0) return 9999;
    if(t[v].deg[1]==0) return 9999;
    if((t[v].deg[0]==1) && (t[v].deg[1]==1)) return 0;
    int best = 9999;
    if(t[v].next==nullptr) {
        if(t[v].nextV >=0) best = 1 + bestl(t[v].nextV);
    }
    else forn(k, 0, K) {
        int nx = t[v].next[k];
        if(nx >= 0) {
            best = min(best, 1+bestl(nx));
        }
    }
    return best;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    //string s;
    int ans = 0;
    t.reserve(30000000);
    t.pb(vertex());
    t[0].deg[0]+=2;
    t[0].deg[1]+=2;
    //memset (t[0].next, 255, sizeof t[0].next);
    sz = 1;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    forn(i,0,s1.size()) add_string(s1, i, 0);
    forn(i,0,s2.size()) add_string(s2, i, 1);
//    cin >> n;
    ans = bestl(0);
    if(ans>5000) cout<<-1;
    else cout<<ans;
    //cout<<ans;
}