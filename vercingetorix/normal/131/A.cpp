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
    int n,m,k;
    ll ans = 0;
    string s;
    bool f = true;
    cin>>s;
    for(int x = 1; x<s.size(); x++) {
        if(s[x]==tolower(s[x])) f=false;
    }
    if(!f) cout<<s;
    else  {
        cout<<(char)((int)tolower(s[0])+toupper(s[0])-s[0]);
        for(int x = 1; x<s.size(); x++) cout<<(char)tolower(s[x]);
    }
    
//    cout<<ans;
}