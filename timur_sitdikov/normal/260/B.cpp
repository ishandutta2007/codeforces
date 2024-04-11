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
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn = 100105;
map<int, int> cnt;
map<int, int>::iterator it;
const int yyy = 1000000, mmm = 1000;

int get_hsh(int yy, int mm, int dd){
    return yy * yyy + mm * mmm + dd;
}

string s;
char good[maxn];

int lim[15];

void output(int dd, int mm, int yy){
    printf("%d%d-%d%d-%d", dd / 10, dd % 10, mm / 10, mm % 10, yy);
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, mm, yy, dd, n, f, mx, maxi;
    int tmp;
    lim[1] = lim[3] = lim[5] = lim[7] = lim[8] = lim[10] = lim[12] = 31;
    lim[4] = lim[6] = lim[9] = lim[11] = 30;
    lim[2] = 28;
    cin >> s;
    n = s.length();
    for(i = 0; i < n; i++){
        good[i] = (s[i] == '-');
        if (!good[i])
            s[i] -= '0';
    }
    for(i = 0; i < n - 9; i++){
        if (!(good[i + 2] && good[i + 5]))
            continue;
        f = 0;
        for(j = 0; j < 9; j++)
            f += good[i + j];
        if (f != 2)
            continue;
        dd = s[i] * 10 + s[i + 1];
        mm = s[i + 3] * 10 + s[i + 4];
        yy = s[i + 6] * 1000 + s[i + 7] * 100 + s[i + 8] * 10 + s[i + 9];
        if (yy < 2013 || yy > 2015)
            continue;
        if (mm < 1 || mm > 12)
            continue;
        if (dd < 1 || dd > lim[mm])
            continue;
        tmp = get_hsh(yy, mm, dd);
        cnt[tmp]++;
    }
    mx = 0;
    f = -1;
    for(it = cnt.begin(); it != cnt.end(); it++){
        if (it->second > mx){
            mx = it->second;
            maxi = it->first;
        }
        else if (it->second == mx)
            f = -1;
    }
    dd = maxi % 100;
    mm = (maxi % yyy) / mmm;
    yy = maxi / yyy;
    output(dd, mm, yy);
}