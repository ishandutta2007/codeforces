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
    string s, s1;
    cin >> n;
    unordered_map<string, int> lvl;
    lvl["polycarp"] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s1;
        cin >> s;
        cin >> s;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l = lvl[s] + 1;
        std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        lvl[s1] = l;
        if (l > ans) {
            ans = l;
        }
    }
    cout << ans;


}