#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

string s1 = "CODEFORCES";
string s2 = "SECROFEDOC";

void solve(){
    string s;
    int i, n, n1 = s1.length(), n2 = s2.length(), l1, l2;
    cin >> s;
    n = s.length();
    for(l1 = 0; l1 < min(n, n1); l1++){
        if (s[l1] != s1[l1]){
            break;
        }
    }
    for(l2 = 0; l2 < min(n, n2); l2++){
        if (s2[l2] != s[n - 1 - l2]){
            break;
        }
    }
    if (l1 + l2 >= 10){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}