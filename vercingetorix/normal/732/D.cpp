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
#include <random>
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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

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
    int n,m;
    scanf("%d %d", &n, &m);
    vi d(n);
    vi a(m);
    forn(i,0,n) {
        scanf("%d", &d[i]);
        d[i]--;
    }
    forn(i,0,m) {
        scanf("%d", &a[i]);
    }
    int l = 2*m-1;
    int r = n+1;
    while(r > l+1) {
        int k = (r+l)/2;
        vi last(m,-1);
        forn(i,0,k) {
            last[d[i]] = i;
        }
        vi exam(k,-1);
        bool f= true;
        forn(i,0,m) {
            if(last[i] == -1) {
                f=false;
                break;
            }
            exam[last[i]] = i;
        }
        
        if(!f) {
            l = k;
            continue;
        }
        int st = 0;
        forn(i,0,k) {
            if(exam[i] == -1) st++;
            else {
                if(a[exam[i]] > st) {
                    f=false;
                    break;
                }
                else {
                    st-=a[exam[i]];
                }
            }
        }
        if(f) {
            r=k;
        }
        else {
            l=k;
        }
    }
    if(r==n+1) {
        cout<<-1;
        return 0;
    }
    else cout<<r;
}