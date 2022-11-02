#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<utility>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<climits>

using namespace std;
typedef long long int lint;
typedef long double ldb;

lint a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    lint ans = 0ll;
    for(int l = 0; l < 63; l++){
        lint o = 0ll;
        for(int i = 0; i <= l; i++){
            o += (1ll << i);
        }
        for(int i = 0; i < l; i++){
            lint n = o - (1ll << i);
            if(a <= n && n <= b){ans++;}
        }
    }
    cout << ans << endl;
    return 0;
}