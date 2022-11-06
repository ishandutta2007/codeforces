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

void solve(){
    /*string s;
    for(int i = 0; i < 6; i++){
        cin >> s;
        cout << "\ts[" << i << "] = " << s << ";\n";
    }*/
    string s[6];
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    int k, i, j;
    cin >> k;
    for(i = 1, j = 1; k; k--){
        s[i][j] = 'O';
        i++;
        if (i == 3 && j != 1){
            i++;
        }
        if (i == 5){
            i = 1;
            j += 2;
        }
    }
    for(i = 0; i < 6; i++){
        cout << s[i] << endl;
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