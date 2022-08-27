#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d",&n,&k);
    vi both,x,y;
    forn(i,0,n) {
        int t,a,b;
        scanf("%d %d %d", &t, &a,&b);
        if(a+b == 2) both.pb(t);
        else if(a==1) x.pb(t);
        else if(b==1) y.pb(t);
    }
    sort(all(both));
    reverse(all(both));
    sort(all(x));
    sort(all(y));
    reverse(all(x));
    reverse(all(y));
    ll time = 0;
    while(k > 0) {
        if(both.size() > 0) {
            if(x.size()>0 && y.size()>0 && x.back()+y.back()<=both.back()) {
                time += x.back()+y.back();
                x.pop_back();
                y.pop_back();
            }
            else {
                time+=both.back();
                both.pop_back();
            }
        }
        else if(y.size()>0 && x.size()>0) {
            time += x.back()+y.back();
            x.pop_back();
            y.pop_back();
        }
        else break;
        k--;
    }
    if(k>0) cout<<-1;
    else cout<<time;
    
}