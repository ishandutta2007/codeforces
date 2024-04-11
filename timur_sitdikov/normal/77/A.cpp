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

map<string, long long> ind;
char g[10][10];
vector<long long> vc[3];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long a[3], v[3], p, tmp, tmp1, mn, cur, mn1;
    ind["Anka"] = 0;
    ind["Chapay"] = 1;
    ind["Cleo"] = 2;
    ind["Troll"] = 3;
    ind["Dracul"] = 4;
    ind["Snowy"] = 5;
    ind["Hexadecimal"] = 6;
    string s1, s2, s3;
    cin >> p;
    for(int i = 0; i < p; i++){
        cin >> s1 >> s2 >> s3;
        g[ind[s1]][ind[s3]] = 1;
    }
    mn = 1000000000000000;
    mn1 = 0;
    cin >> a[0] >> a[1] >> a[2];
    for(int i = 0; i < 3 * 3 * 3 * 3 * 3 * 3 * 3; i++){
        for(int j = 0; j < 3; j++){
            v[j] = 0;
            vc[j].clear();
        }
        tmp = i;
        for(int j = 0; j < 7; j++){
            tmp1 = tmp % 3;
            vc[tmp1].pb(j);
            tmp /= 3;
            v[tmp1]++;
        }
        cur = 0;
        int f = 0;
        for(int j = 0; j < 3; j++){
            if (v[j] == 0){
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        cur = abs(a[0] / v[0] - a[1] / v[1]);
        cur = max(cur, abs(a[0] / v[0] - a[2] / v[2]));
        cur = max(cur, abs(a[1] / v[1] - a[2] / v[2]));
        int cur1 = 0;
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < (int)vc[j].size(); k++){
                for(int l = 0; l < (int)vc[j].size(); l++){
                    if (g[vc[j][k]][vc[j][l]]){
                        cur1++;
                    }
                }
            }
        }
        if (cur < mn || cur == mn && cur1 > mn1){
            mn = cur;
            mn1 = cur1;
        }
    }
    cout << mn << " " << mn1;
}