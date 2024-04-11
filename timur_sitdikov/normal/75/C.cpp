#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

int gcd(int a, int b){
    return b? gcd(b, a % b) : a;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    set<int> st;
    int a, b, g, i, l, r, n, ans;
    cin >> a >> b >> n;
    g = gcd(a, b);
    for(i = 1; i * i <= g; i++){
        if (!(g % i)){
            st.insert(-i);
            st.insert(-g / i);
        }
    }
    st.insert(0);
    for(i = 0; i < n; i++){
        cin >> l >> r;
        ans = -(*(st.lower_bound(-r)));
        if (ans < l)
            ans = -1;
        cout << ans << endl;
    }
}