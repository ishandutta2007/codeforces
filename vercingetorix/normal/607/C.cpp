#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
    int m,k;
    string s1,t,s2;
    ll ans = 0;
    scanf("%d\n", &m);
    getline(cin, s1);
    getline(cin, t);
    for(int i = m-2; i>=0; i--) {
        if(t[i] == 'S') s2.pb('N');
        else if(t[i] == 'N') s2.pb('S');
        else if(t[i] == 'W') s2.pb('E');
        else if(t[i] == 'E') s2.pb('W');
    }
    string s = s2;
    s.pb('$');
    s = s + s1;
    
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    if(pi[n-1] > 0) {
        cout<<"NO";
    }
    else cout<<"YES";
    //cout<<ans;
}