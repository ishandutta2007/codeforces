#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<set>
#include<iostream>
#include<cstdio>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<cassert>
#include<ctime>

#define X first
#define Y second

using namespace std;

typedef long long int lint;
typedef long double ldb;

lint s, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> x;
    if((s - x) % 2 != 0 || s < x){
        printf("0");
        return 0;
    }
    lint pc = __builtin_popcountll(x);
    lint ans = 1ll;
    ans <<= pc;
    lint eq = (s - x)/2;
    for(lint i = 0; i < 63; i++){
        if((eq & (1ll << i)) && (x & (1ll << i))){
            printf("0");
            return 0;
        }
    }
    if(eq == 0)
        ans -= 2;
    cout << ans << endl;
    return 0;
}