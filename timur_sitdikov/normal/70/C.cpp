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
#define xx real()
#define yy imag()

const int maxn = 100000;
const long long INF = 1000000000000000;

int rev(int a){
    int ans = 0;
    while(a){
        ans = ans * 10 + (a % 10);
        a /= 10;
    }
    return ans;
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;   
}

vector<int> vv[maxn + 1];

map<pair<int, int>, int> ind;

set<int, int> mx;

int vec_ind[maxn + 1];

int cnt_of[maxn + 1];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, x, y, rx, xr, a, ra, g, cnt, mxx, mxy, w, curw, xxx, yyy, indy, tmp1;
    long long v = INF, tmp;
    

    cin >> mxx >> mxy >> w;

    for(i = 1; i <= mxx; i++){
        a = i;
        ra = rev(a);
        g = gcd(a, ra);
        a /= g;
        ra /= g;
        if (ind.find(mp(a, ra)) == ind.end()){
            ind[mp(a, ra)] = i;
            for(x = ra, xr = a; x <= mxy; x += ra, xr += a){
                rx = rev(x);
                if (rx == xr){
                    vv[i].pb(x);
                }
            }
            sort(vv[i].begin(), vv[i].end());
        }
        vec_ind[i] = ind[mp(a, ra)];
    }

    /*cnt = 0;
    for(i = 1; i <= maxn; i++){
        cnt += vv[vec_ind[i]].size();
    }
    cout << cnt;*/

    curw = 0;
    y = mxy;
    x = 1;
    for(; ; ){
        if (y == 0 || x > mxx)
            break;
        if (curw < w){
            for(i = 0; i < (int)vv[vec_ind[x]].size(); i++){
                indy = vv[vec_ind[x]][i];
                if (indy > y)
                    break;
                cnt_of[indy]++;
                curw++;
            }
            if (curw >= w){
                tmp = (long long)x * (long long)y;
                if (tmp < v){
                    v = tmp;
                    xxx = x;
                    yyy = y;
                }
            }
            else{
                x++;
            }
        }
        else{
            curw -= cnt_of[y];
            y--;
            tmp1 = 0;
            for(int jj = 1; jj <= y; jj++){
                tmp1 += cnt_of[y];
            }
            if (tmp1 != curw)
                tmp1 = tmp1;
            if (curw >= w){
                tmp = (long long)x * (long long)y;
                if (tmp < v){
                    v = tmp;
                    xxx = x;
                    yyy = y;
                }
            }
            else{
                x++;
            }
        }
    }
    if (v == INF){
        printf("-1");
    }
    else{
        printf("%d %d", xxx, yyy);
    }
}