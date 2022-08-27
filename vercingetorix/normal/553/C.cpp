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
    
    int n,m;
    scanf("%d %d\n",&n,&m);

    vi a(n,0);
    vb u(n, false);
    deque<int> proc;

    int x,y,c;
    vvi nb(n);
    map<pi,int> ed;
    
    fo(i,0,m) {
        scanf("%d %d %d\n",&x,&y, &c);
        x--; y--;
        c=1-c;
        nb[x].pb(y);
        nb[y].pb(x);
        ed[mp(x,y)] = c;
        ed[mp(y,x)] = c;
    }
    bool f;
    int ind=0;
    fo(st,0,n) {
        if(u[st]) continue;
        u[st]=true;
        proc.pb(st);
        a[st]=3;
        f=true;
        while(!proc.empty()) {
            int v=proc.front();
            proc.pop_front();
            u[v]=true;
            for(auto t=nb[v].begin(); t!=nb[v].end(); t++) {
                //if(u[*t]) continue;
                if(ed[mp(v,*t)]==0) {
                    if((a[*t]+a[v])==7) f=false;
                    a[*t]=a[v];
                }
                else {
                    if(a[*t]==a[v]) f=false;
                    a[*t]=7-a[v];
                }
                if(!u[*t]) {
                    u[*t]=true;
                    proc.pb(*t);
                }
            }
        }
        if(!f){
            cout<<"0"<<endl;
            return 0;
        }
        ind++;

    }
    ll p2=1;
    while(ind>1) {
        ind--;
        p2=(2*p2)%mod;
    }
    cout<<p2;
}