#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ff(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define fb(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define xx first
#define yy second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ll long long
#define pii pair<int, int>



using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string s;
int suf[100005];

int get(char x){
    return (int) (x - 'a');
}

int main()
{

    ios::sync_with_stdio(false); cin.tie(0);

    cin >> s;
    int n = (int) s.size(), maks = 0;
    fb(i,n - 1,0){
        maks = max(maks, get(s[i]));
        suf[i] = maks;
    }

    ff(i,0,n - 1){
        if(get(s[i]) == suf[i])cout << s[i];
    }
    return 0;
}