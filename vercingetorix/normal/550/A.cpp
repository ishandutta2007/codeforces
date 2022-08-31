#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
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
    string s;
    cin>>s;
    int l=s.length();
    vi ab,ba;
    for(int i=0; i<l-1; i++) {
        if((s[i]=='A')&&(s[i+1]=='B')) ab.pb(i);
        if((s[i]=='B')&&(s[i+1]=='A')) ba.pb(i);
    }
    if((ab.size()==0)||(ba.size()==0)) {
        cout<<"NO";
        return 0;
    }
    int abs=ab.size()-1;
    int bas=ba.size()-1;
    if((ab[abs]-ba[0])>1) {
        cout<<"YES";
        return 0;
    }
    if((ba[bas]-ab[0])>1) {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
    
}