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

string s;
lint ans = 0ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if((s[i] - '0') % 4 == 0)
            ans++;
        if(i == 0)
            continue;
        int p = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if(p % 4 == 0){
            ans += i;
        }
    }
    cout << ans;
    return 0;
}