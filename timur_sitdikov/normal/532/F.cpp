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

const int MAXN = 4e5 + 5;

char t[MAXN], s[MAXN], c[MAXN];

int cnt[MAXN], lent, lens, pf[MAXN];

int first[200], to[200];

vector<int> ans;

void get_pf(char a, char b){
    int i, j, n = lent + 1 + lens;
    for(i = 0; i < lent; i++){
        c[i] = (t[i] == a ? 1 : 0);
    }
    c[lent] = 2;
    for(i = 0; i < lens; i++){
        c[i + lent + 1] = (s[i] == b ? 1 : 0);
    }
    /*for(i = 0; i < n; i++){
        putchar(c[i] + '0');
    }
    putchar('\n');*/
    for (i = 1; i < n; i++) {
        j = pf[i - 1];
        while (j && c[i] != c[j]){
            j = pf[j - 1];
        }
        if (c[i] == c[j]){
            j++;
        }
        pf[i] = j;
        if (j == lent){
            //printf("%c %c %d\n", a, b, i - lent - lent);
            cnt[i - lent - lent]++;
        }
    }
}

void solve(){
    int i, j;
    scanf("%d%d%s%s", &lens, &lent, &s[0], &t[0]);
    for(i = 'a'; i <= 'z'; i++){
        first[i] = -1;
    }
    for(i = lent - 1; i >= 0; i--){
        first[t[i]] = i;
    }
    for(i = 'a'; i <= 'z'; i++){
        if (first[i] != -1){
            for(j = 'a'; j <= 'z'; j++){
                get_pf(i, j);
            }
        }
    }

    for(i = 0; i < lens - lent + 1; i++){
        int sym_cnt = 0;
        for(j = 'a'; j <= 'z'; j++){
            if (first[j] != -1){
                to[j] = s[first[j] + i];
                sym_cnt++;
            }
        }
        int fl = 0;
        for(j = 'a'; j <= 'z'; j++){
            if (first[j] != -1 && to[to[j]] != j && to[to[j]]){
                //printf("%d %d %d %d\n", i, j, to[j], to[to[j]]);
                fl = 1;
                break;
            }
        }
        if (fl == 0 && cnt[i] == sym_cnt){
            ans.pb(i);  
        }
        //printf("%d %d\n", i, cnt[i]);
    }
    printf("%d\n", (int)ans.size());
    for(i = 0; i < (int)ans.size(); i++){
        printf("%d ", ans[i] + 1);
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
    while(t--){
        solve();    
    }
}