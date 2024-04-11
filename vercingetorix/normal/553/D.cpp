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
double eps=0.00000000001;
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

class rat{
public:
    rat(ll x,ll y, ll z): a(x), b(y), c(z) {};
    ll a;
    ll b;
    int c;
    
};

struct classcomp {
    bool operator() (const rat& lhs, const rat& rhs) const
    {   
        if(lhs.a*rhs.b==rhs.a*lhs.b) return lhs.c<rhs.c;
        else return lhs.a*rhs.b<rhs.a*lhs.b;}
};

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k,m;
    cin>>n>>m>>k;
    vvi nb(n);
    vi allnb(n,0);
    vi krepnb(n,0);
    vb krep(n, false);
    vi origkrep;
    for(int i=0; i<k; i++) {
        int x;
        cin>>x;
        krep[x-1]=true;
        origkrep.pb(x-1);
    }
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        nb[x].pb(y);
        nb[y].pb(x);
        allnb[x]++;
        allnb[y]++;
        if(krep[x]) krepnb[y]++;
        if(krep[y]) krepnb[x]++;
    }
    vector<double> curratio(n);
    fo(i,0,n) curratio[i]=((double)(allnb[i]-krepnb[i]))/((double)(allnb[i]));
    set<rat, classcomp> capture;
    double bestratio=0;
    int bestdel=0;
    vi delorder;
    fo(i,0,n) {
        if(!krep[i]) capture.insert(rat(allnb[i]-krepnb[i], allnb[i], i));
    }
    bestratio=(double)(capture.begin()->a)/(double)(capture.begin()->b);
    fo(i,1,n-k) {
        int curdel=capture.begin()->c;
        capture.erase(capture.begin());
        krep[curdel]=true;
        delorder.pb(curdel);
        for(int j=0; j<nb[curdel].size(); j++) {
            int v=nb[curdel][j];
            if(krep[v]) continue;
            auto it=capture.lower_bound(rat(allnb[v]-krepnb[v], allnb[v], v));
            //while(it->second!=v) it++;
            capture.erase(it);
            krepnb[v]++;
            curratio[v]=((double)(allnb[v]-krepnb[v]))/((double)(allnb[v]));
            capture.insert(rat(allnb[v]-krepnb[v], allnb[v], v));
        }
        double newratio=(double)(capture.begin()->a)/(double)(capture.begin()->b);
        if(newratio>bestratio) {
            bestdel=i;
            bestratio=newratio;
        }
    }
    vb ans(n,true);
    fo(i,0, k) ans[origkrep[i]]=false;
    fo(i,0,bestdel) ans[delorder[i]]=false;
    cout<<n-k-bestdel<<endl;
    fo(i,0,n) if(ans[i]) cout<<i+1<<' ';
}