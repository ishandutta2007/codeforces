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
    pi gde;
};


const int NMAX = 5000000;
vector<vertex> t;
int sz;
int ss;


void add_string (const string & s, int from, bool inv) {
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
        if(inv) t[newv].gde = mp(ss-from, ss-i);
        else t[newv].gde = mp(from+1, i+1);
        v = newv;

    }
    //t[v].leaf = true;
}




int main()
{
    
    sz = 1;
    t.reserve(5000000);
    t.resize(1);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b;
//    ll ans=0;
    string s,tt;
    cin>>s>>tt;
    ss = s.size();
    string s2 = s;
    reverse(all(s2));
    forn(i,0,ss) {
        add_string(s, i, false);
        add_string(s2, i, true);
    }
    int cur =0;
    vpi ans;
    while(cur<tt.size()) {
        int curr = cur;
        int v = 0;
        while(curr<tt.size())  {
//            &&(t[v].next[tt[curr]-'a'] >=0)
            int nv = -1;
            if(t[v].next==nullptr) {
                if(t[v].nextV>=0) if(t[v].nextC==tt[curr]-'a') nv=t[v].nextV;
            }
            else {
                nv=t[v].next[tt[curr]-'a'];
            }
            if(nv==-1) break;
            v = nv;
                        curr++;
        }
        if(curr==cur) {
            cout<<-1;
            return 0;
        }
        ans.pb(t[v].gde);
        cur=curr;
    }
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
}