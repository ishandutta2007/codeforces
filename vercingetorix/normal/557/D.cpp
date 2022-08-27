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
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

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
    //int n,k;
    //cin>>n>>k;
    //for(int i=0; i<n; i++) 
    ll n,m;
    int n1,m1;
    scanf("%d %d\n",&n1,&m1);
    n=n1;
    m=m1;
    
    vi a(n,0);
    vb u(n, false);
    deque<int> proc;
    
    int x,y,c;
    vvi nb(n);
    map<pi,int> ed;
    
    fo(i,0,m) {
        scanf("%d %d\n",&x,&y);
        x--; y--;
        nb[x].pb(y);
        nb[y].pb(x);
        ed[mp(x,y)] = 1;
        ed[mp(y,x)] = 1;
    }
    bool cl=false;
    fo(i,0,n) {
        if(nb[i].size()>1) cl=true;
    }
    if(m==0) {
        ll nn=n;
        cout<<"3 "<<(nn*(nn-1)*(nn-2))/6;
        return 0;
    }
    if(!cl) {
        cout<<"2 "<<m*(n-2);
        return 0;
    }
    bool f;
    ll ans=0;
    int ind=0;
    fo(st,0,n) {
        if(u[st]) continue;
        u[st]=true;
        proc.pb(st);
        a[st]=3;
        f=true;
        ll i3=1;
        ll i4=0;
        while(!proc.empty()) {
            int v=proc.front();
            proc.pop_front();
            u[v]=true;
            for(auto t=nb[v].begin(); t!=nb[v].end(); t++) {
                //if(u[*t]) continue;
                {
                    if(a[*t]==a[v]) f=false;
                    a[*t]=7-a[v];
                }
                if(!u[*t]) {
                    u[*t]=true;
                    if(a[*t]==3) i3++;
                    else i4++;
                    proc.pb(*t);
                }
            }
        }
        ans+=((i3-1)*i3)/2+((i4-1)*i4)/2;
        if(!f){
            cout<<"0 1"<<endl;
            return 0;
        }
        ind++;
        
    }
    cout<<"1 "<<ans;
}