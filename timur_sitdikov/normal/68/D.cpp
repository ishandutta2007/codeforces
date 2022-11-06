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

const int maxh = 31;
map<int, int> cnt;
int h;
double ans = 0.;
double mx = 0.;

void calc(){
    ans = 0.;
    double st2 = 0.5, tmp, tmp1;
    int i, ind, ind1, v, vl, vr, vp;
    mx = 0.;
    ind = 1;
    for(i = 0; i <= h; i++, st2 /= 2.){
        ind1 = ind;
        if (cnt.find(ind) == cnt.end()){
            ans += 2. * st2 * mx;
            break;
        }
        v = cnt[ind];
        if (v <= mx){
            ans += 2. * st2 * mx;
            break;
        }
        if (i == h){
            ans += 2. * st2 * v;
            break;
        }
        else{
            vl = (cnt.find(ind << 1) == cnt.end() ? 0: cnt[ind << 1]);
            vr = (cnt.find((ind << 1) + 1) == cnt.end() ? 0: cnt[(ind << 1) + 1]);
            vp = v - vl - vr;
            if (vl + vp >= vr){
                ans += st2 * max(mx, (double)(vl + vp));
            }
            if (vr + vp >= vl){
                ans += st2 * max(mx, (double)(vr + vp));
            }
            if (vl + vp < vr){
                tmp = vl + vp;
                mx = max(mx, tmp);
                ind = (ind << 1) + 1;
            }
            if (vr + vp < vl){
                tmp = vr + vp;
                mx = max(mx, tmp);
                ind = (ind << 1);
            }
        }
        if (ind == ind1)
            break;
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    char c[10];
    int q, j, a, v;
    scanf("%d %d", &h, &q);
    for(j = 0; j < q; j++){
        scanf("%s", &c);
        if (c[0] == 'd'){
            calc();
            printf("%.12lf\n", ans);
        }
        else{
            scanf("%d %d", &a, &v);
            if (!v)
                continue;
            for(; a; a >>= 1){
                cnt[a] += v;
            }
        }
    }
}