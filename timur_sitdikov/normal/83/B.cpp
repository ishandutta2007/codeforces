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

map<long long, long long> cnt;
map<long long, long long>::iterator it;

pair<long long, long long> pp[MAXN], pp1[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j, f;
    long long k, a, last, n, c, d, lastc, offset, ans, sum;
    scanf("%I64d%I64d", &n, &k);
    sum = 0;
    for(i = 0; i < n; i++){
        scanf("%I64d", &a);
        sum += a;
        pp[i] = mp(a, (long long)(i + 1));
        cnt[a]++;
    }
    if (sum < k){
        printf("-1");
        return 0;
    }
    sort(pp, pp + n);
    last = n;
    lastc = 0;
    offset = 0;
    f = 0;
    for(it = cnt.begin(); it != cnt.end(); lastc = it->first, it++){
        c = it->first - lastc;
        if (k >= last * c){
            k -= last * c;
            last -= it->second;
        }
        else{
            offset = k % last;
            f = 0;
            if (k > last * (c - 1)){
                f = 1;
            }
            break;
        }
    }
    j = 0;
    for(i = n - last; i < n; i++, j++){
        pp1[j] = pp[i];
        swap(pp1[j].first, pp1[j].second);
    }
    sort(pp1, pp1 + last);
    //printf("%I64d\n", f? last - offset: last);
    //rotate(pp1, pp1 + offset, pp1 + last);
    for(i = 0; i < last; i++){
        for(i = offset; i < last; i++){
            printf("%I64d ", pp1[i].first);
        }
    }
    for(i = 0; i < offset; i++){
        if (!f || pp1[i].second != it->first){
            printf("%I64d ", pp1[i].first);
        }
    }
}