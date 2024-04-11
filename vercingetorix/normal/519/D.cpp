#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
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

ll lllabs(ll n){
    if(n<0) return -n;
    return n;
}

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll ans = 0;
    vi cost(26);
    for(int i=0; i<26; i++) cin>>cost[i];
    string s;
    cin>>s;
    vector<pair<ll, int> > costs;
    ll sum=0;
    vector<map<ll, int> > csum(26);
    if(s.length()==1) {
            cout << 0;
            return 0;
    }
    for(int i=0; i<s.length()-1; i++) {
        sum+=cost[s[i]-'a'];
        //costs.pb(mp(sum, i+1));
        csum[s[i]-'a'][sum]++;
        ans+=csum[s[i+1]-'a'][sum];
    }

    cout<<ans;

}