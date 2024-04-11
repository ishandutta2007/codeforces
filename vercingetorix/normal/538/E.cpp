#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
//#include <unordered_map>
#include <map>
#include <list>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n;
    std::vector<std::vector<int> > ch(n+1);
    std::vector<int> par(n+1);
    std::vector<std::vector<int> > nb(n+1);
    std::vector<std::vector<int> > lvl(n+1);
    vi numvis(n+1, 0);
    vi nmax(n+1);
    vi nmin(n+1);
    std::vector<int> v_lvl(n+1,0);
    m=1;
    lvl[1].push_back(1);
    v_lvl[1]=1;
    for(int i=1;i<n;i++){
        int u,v;
        cin >>u>>v;
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

    //for(int i=1; i<=n; i++) cout<<v_lvl[i]<<endl;
    //cout<<l;
    for(int i=l; i>=1; i--) {
        for(int j=0; j<lvl[i].size(); j++) {
            int v=lvl[i][j];
            if(i%2==1) {
                // 
                int cs=ch[v].size();
                if(cs==0) {
                    numvis[v]=1;
                    nmin[v]=1;
                    nmax[v]=1;
                    continue;
                }
                int potmax=n;
                int potmin=0;
                for(int k=0; k<cs; k++) {
                    int u=ch[v][k];
                    numvis[v]+=numvis[u];
                    potmax=min(potmax, numvis[u]-nmax[u]);
                    potmin+=numvis[u]-nmin[u];
                }
                nmax[v]=numvis[v]-potmax;
                nmin[v]=numvis[v]-potmin;
            }
            else {
                int cs=ch[v].size();
                if(cs==0) {
                    numvis[v]=1;
                    nmin[v]=1;
                    nmax[v]=1;
                    continue;
                }
                int potmax=0;
                int potmin=n;
                for(int k=0; k<cs; k++) {
                    int u=ch[v][k];
                    numvis[v]+=numvis[u];
                    potmin=min(potmin, nmin[u]);
                    potmax+=nmax[u]-1;
                }
                nmin[v]=potmin;
                nmax[v]=potmax+1;
            }
        }
    }
    cout<<nmax[1]<<" "<<nmin[1];


}