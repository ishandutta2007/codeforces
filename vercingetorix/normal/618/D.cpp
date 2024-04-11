#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int nn,m,k,xx,yy;
    string s;
    ll ans = 0;
    scanf("%d %d %d", &nn,&xx,&yy);
    ll x= xx;
    ll y=yy;
    ll n = nn;
    std::vector<std::vector<int>> ch(n+1);
    std::vector<int> par(n+1);
    std::vector<std::vector<int>> nb(n+1);
    std::vector<std::vector<int>> lvl(n+1);
    std::vector<int> v_lvl(n+1,0);
    m=1;
    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v;
        //cin >>u>>v;
        scanf("%d %d", &u, &v);
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    
    if(x>=y) {
        bool f=false;
        forn(i, 1, n+1) if(nb[i].size()==n-1) f=true;
        if(f) cout<< (n-2)*y+x;
        else cout<<(n-1)*y;
        return 0;
    }
    ll xtook = 0;
    vi val(n+1, 0);
    for(int lev =l; lev>=2; lev--) {
        for(auto v : lvl[lev]) {
            int u = par[v];
            if ((val[u]<2) && (val[v]<2)) {
                xtook++;
                val[u]++;
                val[v]++;
            }
        }
    }
    
    cout<< xtook*x + (n-1-xtook)*y;
    //cout<<ans;
}