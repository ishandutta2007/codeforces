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
#include <stack>

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
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector < vector<int> > a (n, vector<int> (m));
    vector < vector<int> > nx0 (n, vector<int> (m+1, m));
    string s;
    bool f=false;
    for (int i=0; i<n; ++i){
        //getline(cin, s);
        for (int j=0; j<m; ++j){
            char c;
            //scanf("%c", &c);
            c=getchar();
            a[i][j] = (int)(c-'0');
        }
        scanf("\n");
    }
    forn(i,0,n) {
        for(int j = m-1; j>=0; j--) {
            if(a[i][j] == 0) nx0[i][j] = j;
            else nx0[i][j] = nx0[i][j+1];
        }
    }
    int ans =0;
    vi bin(5001,0);
    forn(l,0,m) {
        vi ones;
        ones.reserve(5000);
        forn(i,0,n) bin[nx0[i][l] - l]++;//ones.pb(nx0[i][l] - l);
        //sort(all(ones));
        //reverse(all(ones));
        for(int i = 5000; i>0; i--) {
            forn(j,0,bin[i]) ones.pb(i);
            bin[i] = 0;
        }
        forn(i,0,ones.size()) {
            ans= max(ans, (i+1)*ones[i]);
        }
        
    }
    printf("%d", ans);


}