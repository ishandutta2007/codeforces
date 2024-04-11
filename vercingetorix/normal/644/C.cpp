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
    int n,m,k;
    string s;
    ll ans = 0;
    //cin >> n;
    scanf("%d\n", &n);
    //cout<<ans;
    map<string, int> hostcode;
    map<string, int> pathcode;
    vi hostn, pathn;
    vector<string> hostname(1);
    vector<string> pathname(1);
    int hostindex=1, pathindex=1;
    vector<pair<vi,int>> whatdo;
    forn(i,0,n) {
        getline(cin, s);
        string host;
        string path;
        auto it = s.find('/', 7);
        if(it==string::npos) {
            host= s;
            path="";
        }
        else {
            host = s.substr(0, it);
            path = s.substr(it, s.size());
        }
        //cout<<"HOST: " << host << " PATH: " <<path<<endl;
        if (hostcode[host] == 0) {
            hostcode[host] = hostindex;
            hostindex++;
            hostname.pb(host);
        }
        if (pathcode[path] == 0) {
            pathcode[path] = pathindex;
            pathindex++;
            pathname.pb(path);
        }
        while(whatdo.size()<hostindex-1) whatdo.pb(mp(vi(), whatdo.size()+1));
        whatdo[hostcode[host]-1].first.pb(pathcode[path]);
        hostn.pb(hostcode[host]);
        pathn.pb(pathcode[path]);
    }
    //for(auto x:whatdo) sort(all(x.first));
    for(int i = 0; i<whatdo.size(); i++) {
        sort(all(whatdo[i].first));
        vi un;
        for(int j = 0; j<whatdo[i].first.size(); j++) {
            if ((j==0) || (whatdo[i].first[j]!=whatdo[i].first[j-1])) un.pb(whatdo[i].first[j]);
        }
        whatdo[i].first = un;
    }
    sort(all(whatdo));
    int curi=whatdo.size() -1;
    vvi groups;
    while(curi>=0) {
        const vi & curv = whatdo[curi].first;
        groups.pb(vi());
        groups.back().pb(whatdo[curi].second);
        curi--;
        while ((curi>=0)&&(whatdo[curi].first==curv)) {
            groups.back().pb(whatdo[curi].second);
            curi--;
        }
        if(groups.back().size() == 1) groups.pop_back();
    }
    printf("%d\n", groups.size());
    for(auto x: groups) {
        for(auto y:x) {
            printf("%s ", hostname[y].c_str());
        }
        printf("\n");
    }
}