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
#include <list>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

char bad[1000];

int is_digit(char c){
    return c >= '0' && c <= '9';
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s, s1, ans;
    int n, i;
    char c;
    for(; (c = getchar()), c != '\n' && c != EOF; ){
        s.pb(c);
    }
    n = s.length();
    for(i = 0; i < n; ){
        if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.'){
            s1.pb('.');
            i += 3;
        }
        else{
            s1.pb(s[i]);
            i++;
        }
    }
    n = s1.length();
    for(i = 0; i < n; i++){
        if (s1[i] == ','){
            ans.pb(',');
            if (i != n - 1){
                ans.pb(' ');
            }
            continue;
        }
        if (s1[i] == '.'){
            if (i != 0 && ans[ans.length() - 1] != ' '){
                ans.pb(' ');
            }
            ans.pb('.');
            continue;
        }
        if (s1[i] == ' '){
            if (ans[ans.length() - 1] != ' '){
                ans.pb(' ');
            }
            continue;
        }
        ans.pb(s1[i]);
    }
    n = ans.length();
    for(i = 0; i < n; i++){
        if (ans[i] != ' ')
            continue;
        if (ans[i + 1] != '.' && ans[i - 1] != ',' && (!is_digit(ans[i - 1]) || !is_digit(ans[i + 1]))){
            bad[i] = 1;
        }
    }
    for(i = 0; i < n; i++){
        if (bad[i])
            continue;
        if (ans[i] == '.'){
            printf("...");
        }
        else {
            putchar(ans[i]);
        }
    }
}