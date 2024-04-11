#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

int cnt[50];
int n;
string s;

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d\n", &n);
    cin >> s;
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        if (x == 4) {cnt[3]++; cnt[2] += 2;} else
        if (x == 6) {cnt[5]++; cnt[3]++;} else
        if (x == 8) {cnt[7]++; cnt[2] += 3; } else  
        if (x == 9) {cnt[7]++; cnt[2]++; cnt[3] += 2; } else
        cnt[x]++;   
    }
    for (int i = 9; i >= 2; i--) {
        for (int j = 0; j < cnt[i]; j++) cout << i;
    }
    cout << endl;
}