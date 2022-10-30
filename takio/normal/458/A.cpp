#include <iostream>
#include <cstring>
#include <cstdio>
#define LL long long
#define pii pair<LL, LL>
using namespace std;

const int N = 100010;
char s[N], t[N], ts[N], tt[N];

int main () {
    scanf ("%s%s", s, t);
    int slen = strlen (s);
    int tlen = strlen (t);
    int mx = max (slen, tlen);
    for (int i = 5; i <= mx + 4; i++){
        if (slen) {
            ts[i] = s[--slen];
        } else {
            ts[i] = '0';
        }
        if (tlen) {
            tt[i] = t[--tlen];
        } else {
            tt[i] = '0';
        }
    }
    for (int i = 0; i < 5; i++)
        ts[i] = tt[i] = '0';
//    for (int i = mx + 4; i >= 5; i--){
//        cout << ts[i];
//    }cout << endl;
//    for (int i = mx + 4; i >= 5; i--){
//        cout << tt[i];
//    }cout << endl;
    for (int i = mx + 4; i >= 2; i--){
//        int cnts = 0, cntt = 0;
        if (ts[i] == '1' && tt[i] == '1'){
            ts[i] = tt[i] = '0';
            continue;
        }
        if (ts[i] == '1' && tt[i - 1] == '1' && tt[i - 2] == '1'){
            ts[i] = tt[i - 1] = tt[i - 2] = '0';
            continue;
        }
        if (tt[i] == '1' && ts[i - 1] == '1' && ts[i - 2] == '1'){
            tt[i] = ts[i - 1] = ts[i - 2] = '0';
            continue;
        }
        if (ts[i] == '1' && ts[i - 1] == '0' && ts[i - 2] == '0'){
            ts[i] = '0'; ts[i - 1] = ts[i - 2] = '1';
            continue;
        }
        if (tt[i] == '1' && tt[i - 1] == '0' && tt[i - 2] == '0'){
            tt[i] = '0'; tt[i - 1] = tt[i - 2] = '1';
            continue;
        }
        if (ts[i] > tt[i]){
            cout << '>';
            return 0;
        }
        if (ts[i] < tt[i]){
            cout << '<';
            return 0;
        }
    }
    cout << '=';
}