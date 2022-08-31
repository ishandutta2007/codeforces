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
    int n;
    deque<int> a, b;
    cin>> n;
    int x;
    for(int i =0; i<n; i++) {
        cin>>x;
        a.pb(x);
    }
    for(int i =0; i<n; i++) {
        cin>>x;
        b.pb(x);
    }
    while(a[0]!=0) {
        a.pb(a[0]);
        a.pop_front();
    }
    while(b[0]!=0) {
        b.pb(b[0]);
        b.pop_front();
    }
    a.pop_front();
    b.pop_front();
    while(b[0]!=a[0]) {
        b.pb(b[0]);
        b.pop_front();
    }
    string ans="YES";
    for(int i =0; i<n-1; i++) if(a[i]!=b[i]) ans="NO";
    cout<<ans;
    
    //cout<<ans;
}