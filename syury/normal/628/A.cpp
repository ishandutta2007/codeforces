#include<string>
#include<vector>
#include<unordered_map>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef long long int lint;
typedef long double ldb;

int ans = 0;

int main(){
    int n, b, p;

    cin >> n >> b >> p;
    int t = p * n;
    while(n > 1){
        int m = 1;
        while(m <= n)
            m <<= 1;
        m >>= 1;
        ans += b * m +  (m/2);
        n = m/2 + n - m;
    }
    cout << ans << " " << t;
    return 0;
}