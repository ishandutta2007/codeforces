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

const int maxn = 100005;

set<pair<int, int> > st;
map<int, int> cnt;
int a[maxn];

void get_ans(){
    int v = st.begin()->first;
    if (v == 1){
        printf("%d\n", -(st.begin()->second));
    }
    else{
        printf("Nothing\n");
    }
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, k, n, v;
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] = -a[i];
    }
    for(i = 0; i < k; i++){
        v = (cnt.find(a[i]) == cnt.end()? 0: cnt[a[i]]);
        if (v){
            st.erase(mp(v, a[i]));
        }
        cnt[a[i]]++;
        st.insert(mp(v + 1, a[i]));
    }
    get_ans();
    for(i = k; i < n; i++){
        v = (cnt.find(a[i]) == cnt.end()? 0: cnt[a[i]]);
        if (v){
            st.erase(mp(v, a[i]));
        }
        cnt[a[i]]++;
        st.insert(mp(v + 1, a[i]));

        v = cnt[a[i - k]];
        st.erase(mp(v, a[i - k]));
        cnt[a[i - k]]--;
        if (v > 1){
            st.insert(mp(v - 1, a[i - k]));
        }
        get_ans();
    }
}