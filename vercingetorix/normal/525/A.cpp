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
    int ans = 0;
    int n;
    cin >> n;
    char c;
    vi keys(26,0);
    for(int i =0; i<n-1;i++) {
        cin>>c;
        keys[c-'a']++;
        cin>>c;
        if(keys[c-'A']==0) ans++;
        else keys[c-'A']--;
    }
    cout<<ans;


}