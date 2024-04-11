#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#define pii pair <char. int>
#define LL long long
using namespace std;

const int N = 1000005;
int a[N], tree[N + 10], res[N];
map<int ,int> mp;

int f(int x){return x & (-x);}

void add(int x, int c){
    for (int i = x; i <= N; i += f(i)){
        tree[i] += c;
    }
}

int sum (int x){
    int res = 0;
    for (int i = x; i >= 1; i -= f(i)){
        res += tree[i];
    }
    return res;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &a[i]);
    }
    mp.clear();
    for (int i = n; i >= 1; i--){
        res[i] = ++mp[a[i]];
        add(res[i], 1);
    }
//    for (int i = 1; i <= n; i++){
//        cout << res[i] <<' ';
//    }
    mp.clear();
    LL ans = 0;
    for (int i = 1; i <= n; i++){
        add(res[i], -1);
        ans += 1LL * sum(++mp[a[i]] - 1);
//        cout << i << ' ' << sum(mp[a[i]] - 1) << endl;
    }
    cout << ans;
}