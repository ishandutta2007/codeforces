#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    ll ans = 0;
    cin >> n;
    vll p(n);
    for(int i =0 ; i<n; i++) cin>>p[i];
    string s;
    cin>>s;
    //cout<<s;
    ll power = 0;
    for(int i =0 ; i<n; i++) {if(s[i]=='B') power+=p[i];}
    ll maxpower = power;
    ll curA = 0, curB = 0;
    for(int i =0 ; i<n; i++) {
        if(s[i]=='B') curB+=p[i];
        else curA+=p[i];
        maxpower = max(maxpower, power -curB+curA);
    }
    
    curA = 0; curB = 0;
    for(int i =n-1 ; i>=0; i--) {
        if(s[i]=='B') curB+=p[i];
        else curA+=p[i];
        maxpower = max(maxpower, power -curB+curA);
    }
    cout<<maxpower;
}