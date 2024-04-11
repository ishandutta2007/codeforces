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
    int n,m,k,a,b;
    string s;
    ll ans = 0;
    cin >> n >> a >> b;
    if (n>(a*b)) {
        cout<<-1;
        return 0;
    }
    vvi r(a, vi(b, 0));
    int cur1=1;
    int cur2=2;
    forn(i,0,a){
        forn(j,0,b) {
            if((i+j)&1) {
                if(cur2<=n) {
                    r[i][j]=cur2;
                    cur2+=2;
                }
            }
            else {
                if(cur1<=n) {
                    r[i][j]=cur1;
                    cur1+=2;
                }
            }
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //cout<<ans;
}