#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define pii pair <int, int>
#define LL long long
using namespace std;

char s[100010];
int a[5];
int main () {
//    for (int i = 0; i <= 3; i++){
//        cout << (int)(pow(1, i) + pow(2, i) + pow(3, i) + pow(4, i)) % 5 << endl;
//    }
    scanf ("%s", s);
    int len = strlen(s), an = 0;
    for (int i = len - 1; i >= len - 2 && i >= 0; i--){
        a[++an] = s[i] - '0';
    }
    int num = a[2] * 10 + a[1], res;
//    cout << num << endl;
    if (num % 4 == 0){
        res = 4;
    }
    else if (num % 4 == 1){
        res = 0;
    }
    cout <<res << endl;
}