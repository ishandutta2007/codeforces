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

unsigned vv[100005];
set<unsigned> st;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    unsigned i, j, offset, k, n, a[4];
    scanf("%u %u", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%u.%u.%u.%u", &a[3], &a[2], &a[1], &a[0]);
        for(j = 0; j < 4; j++){
            vv[i] |= (a[j] << (8 * j));
        }
    }
    for(i = 31; i > 0; i--){
        st.clear();
        for(j = 0; j < n; j++){
            st.insert(vv[j] >> i);
        }
        if (st.size() == k){
            unsigned ans_v = (-1) << i;
            for(j = 0; j < 4; j++){
                a[j] = ((ans_v >> (8 * j)) % 256) % 256;
            }
            printf("%u.%u.%u.%u", a[3], a[2], a[1], a[0]);
            return 0;
        }
    }
    printf("-1");
}