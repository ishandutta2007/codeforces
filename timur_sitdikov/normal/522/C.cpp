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

#define file "cycle"

const int MAXN = 1e5 + 5, INF = 1e8;

int amt[MAXN], pos[MAXN], angry[MAXN], can_be_eaten_early[MAXN];

void solve(){
    int m, k, i, j, amt0, amt0_used, amt00, fl_angry;
    scanf("%d%d", &m, &k);
    for(i = 0; i < k; i++){
        scanf("%d", &amt[i]);
    }
    amt0 = 0;
    for(i = 1; i < m; i++){
        scanf("%d%d", &pos[i], &angry[i]);
        pos[i]--;
        if (pos[i] == -1){
            amt0++;
        }
    }
    /*putchar('#');
    return;*/
    amt00 = 0;
    fl_angry = 0;
    amt0_used = INF;
    for(i = 1; i < m; i++){
        if (angry[i] && !fl_angry){
            fl_angry = 1;
            for(j = 0; j < k; j++){
                can_be_eaten_early[j] = 1;
            }
            for(j = i; j < m; j++){
                if (pos[j] != -1){
                    can_be_eaten_early[pos[j]] = 0;
                }
            }
            for(j = 0; j < k; j++){
                if (can_be_eaten_early[j] == 1){
                    if (amt[j] > amt00){
                        can_be_eaten_early[j] = 0;
                    } else {
                        if (amt[j] < amt0_used){
                            amt0_used = amt[j];
                        }
                    }
                }
            }
        }
        if (pos[i] == -1){
            amt00++;
        } else {
            amt[pos[i]]--;
        }
    }
    for(i = 0; i < k; i++){
        if (!fl_angry){
            if (amt[i] <= amt0){
                putchar('Y');
            } else {
                putchar('N');
            }
        } else {
            if (can_be_eaten_early[i]){
                putchar('Y');
            } else {
                if (amt[i] <= amt0 - amt0_used){
                    putchar('Y');
                } else {
                    putchar('N');
                }
            }
        }
    }
    putchar('\n');
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while(t--){
        solve();    
    }
}