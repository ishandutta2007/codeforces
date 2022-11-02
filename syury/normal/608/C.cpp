#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>

using namespace std;
typedef long long int lint;

const int inf = 1e9;

int n;
vector<pair<int, int> > a;
vector<int> dp;
set<int> s;
map<int, int> mp;
int opt = inf;

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    dp.resize(n);
    for(int i = 0; i < n; i++){
        int v, u;
        cin >> v >> u;
        a[i] = make_pair(v, u);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        dp[i] = inf;
        int k = 0;
        auto it = s.lower_bound(a[i].first - a[i].second);
        if(it != s.begin()){it--;}
        else{k = -1;}
        if(k != -1){k = mp[*it];}
        if(k == -1){dp[i] = i;}
        else{
            dp[i] = dp[k] + (i - k - 1);
        }
        s.insert(a[i].first);
        mp.insert(make_pair(a[i].first, i));
        opt = min(opt, dp[i] + n - i - 1);
        //cout << dp[i] << endl;
    }
    cout << opt << endl;
	return 0;
}