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
#include<cassert>

using namespace std;

typedef long long int lint;
typedef long double ldb;

string s;
lint ans = 0ll;

char get(char c, int rng){
    if(c - rng >= 'a')
        return c - rng;
    if(c + rng <= 'z')
        return c + rng;
    assert(false);
    return 0;
}

char maxrng(char c){
    if(c - 'a' > 'z' - c)
        return 'a';
    else
        return 'z';
}

int rng(char c, char h){
    return abs(c - h);
}

int k, n;
string t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> k;
    cin >> s;
    t = s;
    for(int i = 0; i < n; i++){
        char e = maxrng(s[i]);
        int r = rng(e, s[i]);
        if(r > k){
            t[i] = get(s[i], k);
            r = k;
        }
        else{
            t[i] = e;
        }
        k -= r;
    }
    if(k > 0)
        {cout << -1; return 0;}
    cout << t;
    return 0;
}