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
    int n,k;
    scanf("%d %d\n", &n, &k);
    vi a(n+1);
    vi b(n+1,0);
    int turns = 0;
    forn(i,0,n+1) {
        string s;
        getline(cin, s);
        if(s[0]=='?') b[i] = 1;
        else {
            a[i] = stoi(s);
            turns++;
        }
    }
    if(turns == (n+1)) {
        int cur = 0;
        if(k==0) {
            if(a[0]==0) cout<<"Yes";
            else cout<<"No";
            return 0;
        }
        forn(i,0,n+1) {
            if(cur%k != 0) {
                cout<<"No";
                return 0;
            }
            cur = cur/k + a[i];
        }
        if(cur!=0) cout<<"No";
        else cout<<"Yes";
        return 0;
    }
    if(n&1) {
        //human last
        if(k!=0) {
            cout<<"Yes";
            return 0;
        }
        else {
            if(b[0]==1) {
                //not filled
                if(turns&1) cout<<"Yes";
                else cout<<"No";
                return 0;
            }
            else {
                if(a[0] == 0) cout<<"Yes";
                else cout<<"No";
                return 0;
            }
        }
    }
    else {
        if(k!=0) {
            cout<<"No";
            return 0;
        }
        else {
            if(b[0]==1) {
                //not filled
                if(turns&1) cout<<"Yes";
                else cout<<"No";
                return 0;
            }
            else {
                if(a[0] == 0) cout<<"Yes";
                else cout<<"No";
                return 0;
            }
        }
    }
    
}