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

using namespace std;
typedef long long int lint;
vector<int> a;
set<int> s;
int gm = 1e9 + 10;
int n;
long long int ans = 0ll;

int range(int l, int r){
    if(l <= r){return r - l + 1;}
    else{
        return n - (l - r - 1);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < gm){
            gm = a[i];
            s.clear();
        }
        if(a[i] == gm){s.insert(i);}
    }
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(i);
        if(it == s.end()){it = s.begin();}
        int w = *it;
        long long int curr = gm * 1ll * n + range(i, w) - 1;
        //cout << curr << " at " << i << endl;
        ans = max(ans, curr);
    }
    cout << ans << endl;
	return 0;
}