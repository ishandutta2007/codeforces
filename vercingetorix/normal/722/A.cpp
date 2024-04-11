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
    int n;
    scanf("%d\n", &n);
    string s;
    getline(cin, s);
    if(s[3] > '5') s[3] = '5';
    if(n==12) {
        if(s[0]=='0' && s[1]=='0') {
            s[1] = '1';
        }
        else if(s[0] > '1') {
            if(s[1] =='0') s[0] = '1';
            else s[0]='0';
        }
        else if(s[0] == '1' && s[1] > '2') s[1] = '1';
    }
    else if(n==24) {
        if(s[0] > '2' || (s[0]=='2' && s[1] > '3')) s[0] = '0';
    }
    cout<<s;
    
    
}