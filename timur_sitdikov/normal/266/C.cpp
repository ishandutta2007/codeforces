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

const int maxn = 1005;
pair<int, int> mm[maxn];
vector<int> inds;

vector<pair<int, pair<int, int>  > > ans;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, k, last, tmp, mx;
    scanf("%d", &n);
    for(i = 1; i < n; i++){
        scanf("%d %d", &mm[i].first, &mm[i].second);
    }
    mx = n;
    for(j = n; j >= 1; j--){
        inds.clear();
        for(i = 1; i < n; i++){
            if (mm[i].second == j && mm[i].first <= mx){
                inds.pb(mm[i].first);
            }
        }
        sort(inds.begin(), inds.end());
        for(tmp = 0, i = inds.size() - 1; i >= 0; i--, tmp++){
            if (inds[i] != mx - tmp){
                ans.pb(mp(1, mp(inds[i], mx - tmp)));
                for(k = 1; k < n; k++){
                    if (mm[k].first == inds[i]){
                        mm[k].first = mx - tmp;
                    }
                    else if (mm[k].first == mx - tmp){
                        mm[k].first = inds[i];
                    }
                }
            }
        }
        mx -= tmp;
    }
    for(j = 1, last = 1; j <= n; j++){
        int f = 0;
        for(i = 1; i < n; i++){
            if (mm[i].second == j){
                f = 1;
            }
        }
        if (f){
            if (j != last){
                ans.pb(mp(2, mp(last, j)));
                for(k = 1; k <= n; k++){
                    if (mm[k].second == last){
                        mm[k].second = j;
                    }
                    else if (mm[k].second == j){
                        mm[k].second = last;
                    }
                }
            }
            last++;
        }
    }
    printf("%d\n", (int)ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
    }
}