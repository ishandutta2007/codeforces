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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    //string s;
    ll ans = 0;
    scanf("%d", &n);
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
        scanf("%d %d", &u,&v);
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
    
    vi vclass(n+1, 0);
    vi val(n+1,0);
    // 0 - ->, 1 - line, 2 - cross, 3 - cut, 4 - cutcross
    for(int lev= l; lev>=1; lev--) {
        for(auto v:lvl[lev]) {
            if(ch[v].size()==0) vclass[v] = 0;
            else if(ch[v].size()==1) {
                int u=ch[v][0];
                if(vclass[u]==0) vclass[v]=0;
                else if(vclass[u]==1) vclass[v]=2;
                else if(vclass[u]==2) vclass[v]=2;
                else if(vclass[u]==3) {
                    vclass[v]=3;
                    if(val[u]==3) val[v]=2;
                    else val[v]=1;
                }
            }
            else if(ch[v].size()>=2) {
                vi cc;
                int freeval;
                for(auto x:ch[v]) {
                    cc.pb(vclass[x]);
                    if(vclass[x]==3) freeval=val[x];
                }
                sort(all(cc));
                reverse(all(cc));
                if(cc[0]==3) {
                    if((cc[1]>0)||(cc.size()>3)) {
                        cout<<"No";
                        return 0;
                    }
                    vclass[v]=3;
                    val[v]=1;
                    if(freeval==3) {
                        if(cc.size()==3) {
                            if(v!=1){
                                cout<<"No";
                                return 0;
                            }
                        }
                    }
                    else {
                        if(cc.size()==3) {
                                cout<<"No";
                                return 0;
                        }
                        if(v!=1){
                            cout<<"No";
                            return 0;
                        }
                    }
                }
                else if(cc[0]==2) {
                    if(cc[1]==2) {
                        vclass[v]=3;
                        val[v]=3;
                        if(cc.size()>2) if(cc[2]==2) {
                            cout<<"No";
                            return 0;
                        }
                    }
                    else vclass[v]=2;
                }
                else if(cc[0]==1) vclass[v]=2;
                else {
                    if(cc.size()==2) vclass[v]=1;
                    else vclass[v] =2;
                }
                // c1<=c2
                
            }
            
        }
    }
    cout<<"Yes";
    // cout<<ans;
}