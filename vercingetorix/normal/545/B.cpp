#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

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
    int n,m;
    string s,t;
    cin >> s;
    cin >> t;
    int l=s.length();
    int d = 0;
    for(int i=0; i<l; i++) if(s[i]!=t[i]) d++;
    if((d%2) == 1) {
        cout<<"impossible";
        return 0;
    }
    d/=2;
    int i=0;
    string a;
    while(d>0) {
        a.pb(t[i]);
        if(s[i]!=t[i]) d--;
        i++;
    }
    while(i<l) {
        a.pb(s[i]);
        i++;
    }
    cout<<a;


}