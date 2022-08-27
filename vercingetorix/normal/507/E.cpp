#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m,mm;
    cin>>n>>mm;
    std::vector<std::vector<int>> ch(n+1);
    std::vector<int> par(n+1);
    std::vector<std::vector<int>> nb(n+1);
    std::vector<std::set<int>> lvl(n+1);
    std::vector<int> v_lvl(n+1,0);
    std::vector<int> min_broken(n+1,n+2);
    map<pi, int> status;
    vpi edges;
    int broken=0;
    for(int i=0;i<mm;i++){
        int u,v,x;
        cin >>u>>v>>x;
        if(x==0) broken++;
        u--;
        v--;
        edges.pb(mp(u,v));
        nb[u].push_back(v);
        nb[v].push_back(u);
        status[mp(u,v)] = 1-x;
        status[mp(v,u)] = 1-x;
    }
    m=1;
    lvl[1].insert(0);
    v_lvl[0]=1;
    int l=2;
    min_broken[0]=0;
    while(m<n){
        for(auto k=lvl[l-1].begin(); k!=lvl[l-1].end(); k++){
            int v=*k;
            for(int h=0; h<nb[v].size();h++){
                if((v_lvl[nb[v][h]]==0)||((v_lvl[nb[v][h]]==l)&&(min_broken[nb[v][h]]>(min_broken[v]+status[mp(v,nb[v][h])])))){
                    if(v_lvl[nb[v][h]]==0) m++;
                    v_lvl[nb[v][h]]=l;
                    lvl[l].insert(nb[v][h]);
                    min_broken[nb[v][h]]=(min_broken[v]+status[mp(v,nb[v][h])]);
                    //m++;
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    int mind=v_lvl[n-1]-v_lvl[0];
    int rep=min_broken[n-1];
    cout<<(mm-mind+2*rep-broken)<<endl;
    int cur=n-1;
    
    while(cur!=0) {
        status[mp(par[cur], cur)]+=2;
        status[mp(cur, par[cur])]+=2;
        cur=par[cur];
    }
    for(int i=0; i<edges.size(); i++) {
        if(status[edges[i]]==0) cout<<edges[i].first+1<<" "<<1+edges[i].second<<" 0"<<endl;
        if(status[edges[i]]==3) cout<<edges[i].first+1<<" "<<1+edges[i].second<<" 1"<<endl;
    }
}