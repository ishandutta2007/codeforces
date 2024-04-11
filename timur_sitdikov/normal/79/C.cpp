#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 100100;

string s, s1[10], s2;
int pf[MAXN];

int last[10][MAXN];

void get_pf(){
    int i, j;
    for(i = 1; i < s2.length(); i++){
        for(j = pf[i - 1]; j && s2[j] != s2[i]; j = pf[j - 1]);
        if (s2[j] == s2[i]){
            j++;
        }
        pf[i] = j;
    }
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, offset, l, lst, len, pos;
    cin >> s >> n;
    l = s.length();
    for(i = 0; i < n; i++){
        for(j = 0; j < l; j++){
            last[i][j] = -1;
        }
    }
    for(i = 0; i < n; i++){
        cin >> s1[i];
        s2 = s1[i] + "#" + s;
        get_pf();
        offset = s1[i].length() + 1;
        for(j = offset; j < l + offset; j++){
            if (pf[j] == offset - 1){
                last[i][j - offset] = j - offset - (offset - 2);
            }
        }
    }
    lst = -1;
    len = -1;
    pos = -1;
    for(i = 0; i < l; i++){
        for(j = 0; j < n; j++){
            lst = max(lst, last[j][i]);
        }
        if (len < i - lst){
            len = i - lst;
            pos = i - len + 1;
        }
    }
    if (len == 0){
        cout << "0 0";
        return 0;
    }
    cout << len << " " << pos;
}