#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

typedef long long ll;

using namespace std;
// want less than k strictly more than num
ll get_more_than(ll &n, ll &m, ll num){
    ll count = 0;
    for(ll i = 1; i < n+1; i++){
        if(i * m <= num){
            continue;
        }
        // less than is num/i
        count += m - num / i;
    }
    return count;
}

// looked at editorial!
int main(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll a = 1;
    ll b = n * m;
    while(a < b){
        ll mid = (a + b) / 2;
        ll more_than = get_more_than(n, m, mid);
        // printf("a %lld b %lld mid %lld more_than %lld\n", a, b, mid, more_than);
        if(more_than > m * n - k){
            a = mid + 1;
        }
        else{
            b = mid;
        }
    }
    cout << a << endl;
    return 0;
}