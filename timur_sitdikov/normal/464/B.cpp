#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

struct point{
    ll x, y, z;
    int ind;
    point(){}
    point(ll _x, ll _y, ll _z){
        x = _x, y = _y, z = _z;
    }
};

const ll BASE = 2e6 + 1, OFFSET = 1e6;

point operator + (const point &a, const point &b){
    return point(a.x + b.x, a.y + b.y, a.z + b.z);
}

point operator - (const point &a, const point &b){
    return point(a.x - b.x, a.y - b.y, a.z - b.z);
}

bool operator < (const point &a, const point &b){
    ll va = a.z + OFFSET + BASE * (a.y + OFFSET + BASE * (a.x + OFFSET));
    ll vb = b.z + OFFSET + BASE * (b.y + OFFSET + BASE * (b.x + OFFSET));
    return va < vb;
}


ll dot(point &o, point &a, point &b){
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y) + (a.z - o.z) * (b.z - o.z);
}

ll abs(point &a, point &b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
}

ll tmp[30][30];

ll tmp1[40], tmp2[40], tmp3[40];

point pp[80], pp1[80], pt[80];

ll m1[30], m2[30];
int ind[80];

int check(){
    int i, j, k, l, fl;
    for(i = 0; i < 4; i++){
        pp1[i] = pp[i];
    }
    pp1[4] = pp[1] + pp[2] - pp[0];
    pp1[5] = pp[2] + pp[3] - pp[0];
    pp1[6] = pp[3] + pp[1] - pp[0];
    pp1[7] = pp[1] + pp[2] + pp[3] - pp[0] - pp[0];
    for(j = 0; j < 24; j++){
        fl = 0;
        for(k = 4; k < 8; k++){
            m1[0] = pp1[k].x, m1[1] = pp1[k].y, m1[2] = pp1[k].z;
            sort(m1, m1 + 3);
            m2[0] = pp[k].x, m2[1] = pp[k].y, m2[2] = pp[k].z;
            sort(m2, m2 + 3);
            if (m1[0] != m2[0] || m1[1] != m2[1] || m1[2] != m2[2]){
                fl = 1;
                break;
            }
        }
        if (!fl){
            /*for(i = 1; i < 8; i++){
                for(j = 4; j < 8; j++){
                    if (pp[j].x == pt[i].x && pp[j].y == pt[i].y && pp[j].z == pt[i].z){
                        ind[i] = j;
                        break;
                    }
                }
            }*/
            return 1;
        }
        next_permutation(pp + 4, pp + 8);
    }
    return 0;
}

void solve(){
    int i, i1, i2, i3, j, j1, j2, j3, k, top;
    for(i = 0; i < 8; i++){
        cin >> pt[i].x >> pt[i].y >> pt[i].z;
        pt[i].ind = i;
    }
    for(i1 = 1; i1 < 8; i1++){
        for(i2 = i1 + 1; i2 < 8; i2++){
            for(i3 = i2 + 1; i3 < 8; i3++){
                tmp1[0] = pt[i1].x, tmp1[1] = pt[i1].y, tmp1[2] = pt[i1].z;
                for(j1 = 0; j1 < 6; j1++, next_permutation(tmp1, tmp1 + 3)){
                    pt[i1].x = tmp1[0], pt[i1].y = tmp1[1], pt[i1].z = tmp1[2];
                    tmp2[0] = pt[i2].x, tmp2[1] = pt[i2].y, tmp2[2] = pt[i2].z;
                    for(j2 = 0; j2 < 6; j2++, next_permutation(tmp2, tmp2 + 3)){
                        pt[i2].x = tmp2[0], pt[i2].y = tmp2[1], pt[i2].z = tmp2[2];
                        tmp3[0] = pt[i3].x, tmp3[1] = pt[i3].y, tmp3[2] = pt[i3].z;
                        for(j3 = 0; j3 < 6; j3++, next_permutation(tmp3, tmp3 + 3)){
                            pt[i3].x = tmp3[0], pt[i3].y = tmp3[1], pt[i3].z = tmp3[2];
                            ll v = abs(pt[i1], pt[0]);
                            ll v1 = abs(pt[i2], pt[0]);
                            ll v2 = abs(pt[i3], pt[0]);
                            if (!v || v1 != v || v2 != v){
                                continue;
                            }
                            if (dot(pt[0], pt[i1], pt[i2]) || dot(pt[0], pt[i2], pt[i3]) || dot(pt[0], pt[i3], pt[i1])){
                                continue;
                            }
                            pp[0] = pt[0];
                            pp[1] = pt[i1];
                            pp[2] = pt[i2];
                            pp[3] = pt[i3];
                            top = 4;
                            for(k = 1; k < 8; k++){
                                if (k != i1 && k != i2 && k != i3){
                                    pp[top] = pt[k];
                                    top++;
                                }
                            }
                            if (check()){
                                printf("YES\n");
                                for(k = 0; k < 8; k++){
                                    if (k == 0 || k == i1 || k == i2 || k == i3){
                                        printf("%lld %lld %lld\n", pt[k].x, pt[k].y, pt[k].z);
                                    } else {
                                        for(j = 4; j < 8; j++){
                                            if (pp[j].ind == pt[k].ind){                                        
                                                //printf("%d %d ", k, j);
                                                printf("%lld %lld %lld\n", pp1[j].x, pp1[j].y, pp1[j].z);
                                                break;
                                            }
                                        }
                                    }
                                }
                                return;
                            }
                        }
                    }
                    ;
                }
            }
        }
    }
    printf("NO\n");
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}