#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef pair<int, int> ii;
int n, a[101];
vector<ii> ans;
 
int cnt3(int x){
    int ans = 0;
    while(x % 3 == 0){
        ans++;
        x /= 3;
    }
    return ans;
}
 
signed main(){
	//freopen("B_09.in", "r", stdin);
	//freopen("B_09.ans", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans.push_back({-cnt3(a[i]), a[i]});
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) cout << ans[i].second << " ";
}