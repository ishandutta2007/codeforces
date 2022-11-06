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

const int d = 405, offset = 200;

int col[d][d][4];

pair<int, int> moves[20];

vector<pair<int, int> > vc;

int sq_abs(pair<int, int> &a){
    return a.xx * a.xx + a.yy * a.yy;
}

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.xx + a.yy > b.xx + b.yy;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x, y, d, i, i1, j, n, x1, y1, vv, last;
    pair<int, int> tmp;
    cin >> x >> y >> n >> d;
    for(i = 0; i < n; i++){
        cin >> moves[i].xx >> moves[i].yy;
    }
    for(i = -200; i <= 200; i++){
        for(j = -200; j <= 200; j++){
            tmp = mp(i, j);
            if (sq_abs(tmp) <= d * d){
                vc.pb(tmp);
            }
        }
    }
    sort(vc.begin(), vc.end(), cmp);
    last = 0;
    for(i = 0; i < (int)vc.size(); i++){
        for(j = 0; j < n; j++){
            tmp = mp(vc[i].xx + moves[j].xx, vc[i].yy + moves[j].yy);
            if (sq_abs(tmp) > d * d){
                continue;
            }
            tmp.xx += offset, tmp.yy += offset;
            if (!col[tmp.xx][tmp.yy][0]){
                col[vc[i].xx + offset][vc[i].yy + offset][0] = 1;
            }
            if (!col[tmp.xx][tmp.yy][2]){
                col[vc[i].xx + offset][vc[i].yy + offset][1] = 1;
            }
            if (!col[tmp.xx][tmp.yy][1]){
                col[vc[i].xx + offset][vc[i].yy + offset][2] = 1;
            }
            if (!col[tmp.xx][tmp.yy][3]){
                col[vc[i].xx + offset][vc[i].yy + offset][3] = 1;
            }
        }
        if (i > 0 && vc[i].xx + vc[i].yy < vc[i - 1].xx + vc[i - 1].yy){
            i1 = i;
            for(i = last; i < i1; i++){
                x1 = vc[i].yy + offset, y1 = vc[i].xx + offset;
                if (!col[x1][y1][0]){
                    vv = vc[i].xx * vc[i].xx + vc[i].yy * vc[i].yy;
                    col[vc[i].xx + offset][vc[i].yy + offset][1] = 1;
                }
            }
            for(i = last; i < i1; i++){
                x1 = vc[i].yy + offset, y1 = vc[i].xx + offset;
                if (!col[x1][y1][1]){
                    vv = vc[i].xx * vc[i].xx + vc[i].yy * vc[i].yy;
                    col[vc[i].xx + offset][vc[i].yy + offset][3] = 1;
                }
            }
            last = i;
        }
    }
    i1 = i;
    for(i = last; i < i1; i++){
        x1 = vc[i].yy + offset, y1 = vc[i].xx + offset;
        if (!col[x1][y1][0]){
            vv = vc[i].xx * vc[i].xx + vc[i].yy * vc[i].yy;
            col[vc[i].xx + offset][vc[i].yy + offset][1] = 1;
        }
    }
    for(i = last; i < i1; i++){
        x1 = vc[i].yy + offset, y1 = vc[i].xx + offset;
        if (!col[x1][y1][1]){
            vv = vc[i].xx * vc[i].xx + vc[i].yy * vc[i].yy;
            col[vc[i].xx + offset][vc[i].yy + offset][3] = 1;
        }
    }
    last = i;
    if (col[x + offset][y + offset][3]){
        printf("Anton");
    }
    else{
        printf("Dasha");
    }
}