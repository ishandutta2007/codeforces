#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

std::vector<std::vector<int>> ch(500000+1);
std::vector<int> par(500000+1);
vector<int> nl;
int l;

void bfs(int ind) {
    if (ch[ind].size() == 0) {
        while (nl.size() < l + 1) nl.pb(0);
        nl[l]++;
        return;
    }
    else {
        for(auto a : ch[ind]) {
            l++;
            bfs(a);
            l--;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d\n", &n);
    
    std::vector<std::vector<int>> nb(n+1);
    std::vector<std::vector<int>> lvl(n+1);
    std::vector<int> v_lvl(n+1,0);
    m=1;
    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v;
        //cin >>u>>v;
        scanf("%d %d\n", &u, &v);
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    l=2;
    
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
    for(int i = 1; i <= l; i++) lsize[i]=lvl[i].size();
    //vi nl(l+1, 0);
    int ans = 0;
    for(auto root: ch[1]) {
        l=1;
        nl.clear();
        bfs(root);
        l = nl.size() - 1;
        for(int i = 1; i<l; i++) {
            if(nl[i]>0) nl[i+1]+=nl[i]-1;
        }
        ans = max(ans, l+nl[l]-1);

    }
    cout<<ans;
    /*for(int i = 1; i<=l; i++) {
        for (auto a: lvl[i]) {
            if(ch[a].size() == 0) nl[i]++;
        }
    }
    for(int i = 3; i<l; i++) {
        if(nl[i]>0) nl[i+1]+=nl[i]-1;
    }
    cout<<l-1+nl[l]-1; */
}