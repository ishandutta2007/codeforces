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

const int MAXN = 100005;

long long tt[4 * MAXN][5], v[MAXN];
int cnt[4 * MAXN];

map<long long, int> ind;
map<long long, int>::iterator it;

int qq[MAXN], tp[MAXN];

void update(int pos, int tl, int tr, int wh, long long val){
    if (tl == tr){
        tt[pos][0] = val;
        cnt[pos] ^= 1;
        return;
    }
    int j, tm = (tl + tr) >> 1;
    if (wh <= tm){
        update(pos << 1, tl, tm, wh, val);
    }
    else{
        update((pos << 1) + 1, tm + 1, tr, wh, val);
    }
    cnt[pos] = cnt[pos << 1] + cnt[(pos << 1) + 1];
    for(j = 0; j < 5; j++){
        tt[pos][j] = 0;
    }
    for(j = 0; j < 5; j++){
        tt[pos][j] += tt[pos << 1][j];
        tt[pos][(j + cnt[pos << 1]) % 5] += tt[(pos << 1) + 1][j];
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, top;
    long long val;
    char s[10];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", &s, &qq[i]);
        if (s[0] == 'a'){
            tp[i] = 0;
        }
        if (s[0] == 'd'){
            tp[i] = 1;
        }
        if (s[0] == 's'){
            tp[i] = 2;
        }
        else{
            scanf("%i64d", &qq[i]);
            ind[qq[i]] = 0;
        }
    }
    top = ind.size();

    for(i = 0, it = ind.begin(); it != ind.end(); it++, i++){
        it->second = i;
        v[i] = it->first;
    }

    for(i = 0; i < n; i++){
        if (tp[i] == 2){
            printf("%I64d\n", tt[1][2]);
            continue;
        }
        if (tp[i] == 0){
            val = qq[i];
        }
        else{
            val = 0;
        }
        update(1, 0, top - 1, ind[qq[i]], val);
    }
}