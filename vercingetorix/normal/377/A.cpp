#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
    int n,m,k;
    string s;
    //ll ans = 0;
    cin >> n >> m>>k;
    vvi a(n, vi(m,0));
    vector<vector<char>> ans(n, vector<char>(m));
    char c;
    vb sv(n*m,false);
    vi vv;
    forn(i,0,n) forn(j,0,m) {
        cin>>c;
        ans[i][j]=c;
        if(c=='#') a[i][j]=1;
        else {
            sv[i*m+j] = true;
            vv.pb(i*m+j);
        }
        
    }
    //sv.pb(n*m+10);
    int N = vv.size();
    vb u(N, false);
    
    u[0]=true;
    std::vector<std::vector<int>> ch(n*m+1);
    std::vector<int> par(n*m+1);
    std::vector<std::vector<int>> nb(n*m+1);
    std::vector<std::vector<int>> lvl(n*m+1);
    std::vector<int> v_lvl(n*m+1,0);
    forn(i,0,N) {
        int v=vv[i];
        if(v%m < m-1) if(sv[v+1]) nb[v].pb(v+1);
        if(v%m > 0) if(sv[v-1]) nb[v].pb(v-1);
        if(v/m > 0) if(sv[v-m]) nb[v].pb(v-m);
        if(v/m < n-1) if(sv[v+m]) nb[v].pb(v+m);
    }
    int mm=1;
    lvl[1].push_back(vv[0]);
    v_lvl[vv[0]]=1;
    
    int l=2;
    
    while(mm<N){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    mm++;
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
    while(k>0) {
        if(lvl[l].size() > 0) {
            int v=lvl[l].back();
            lvl[l].pop_back();
            k--;
            ans[v/m][v%m] = 'X';
        }
        else {
            l--;
        }
    }
    forn(i,0,n) {
        forn(j,0,m) cout<<ans[i][j];
        cout<<endl;
    }
    //cout<<ans;
}