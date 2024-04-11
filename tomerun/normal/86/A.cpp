#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;
typedef long long ll;

ll l, r;

int main()
{
    cin >> l >> r;
    ll base = 1;
    while(base * 10 <= r) {
        base *= 10;
    }
    ll ans = 0;
    if(l <= base * 5 - 1 && base * 5 - 1 <= r){
        ans = (base * 5 - 1)*base * 5;
    } else if(l <= base * 5 && base * 5 <= r) {
        ans = (base * 5 - 1)*base * 5;
    }else if (r < base * 5) {
        ans = r * (base*10 - 1 - r);
    }else{
        ans = l * (base*10 - 1 - l);
    }
    cout << ans << endl;
    return 0;
}