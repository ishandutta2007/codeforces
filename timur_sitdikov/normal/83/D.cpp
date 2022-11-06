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

const int MAXN = 225000000;

char p[MAXN];

char pp[100000];

int pr[100000], top, cnt[100000], n;

int calc(int r){
    if (r < n){
        return (r >= 1);
    }
    int g, last_g, i, j, ans;
    for(i = 0; i < top; i++){
        cnt[i] = r / pr[i];
    }
    last_g = 0;
    long long curv = 1;
    ans = r;
    char bit_cnt;
    for(i = 1; i < (1 << top); ){
        bit_cnt = 0;
        curv = 1;
        for(j = 0; j < top; j++){
            if (i & (1 << j)){
                bit_cnt ^= 1;;
                curv *= pr[j];
                if (curv > r)
                    break;
            }
        }
        if (curv > r){
            for(j = 0; !(i & (1 << j)); j++);
            for(; j < top && (i & (1 << j)); j++){
                i ^= (1 << j);
            }
            if (j == top)
                break;
            i ^= (1 << j);
            continue;
        }
        if (bit_cnt){
            ans -= r / curv;
        }
        else{
            ans += r / curv;
        }
        i++;
    }
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b, i, j, ans;
    scanf("%d %d %d", &a, &b, &n);
    for(i = 2; i * i <= n; i++){
        if (!(n % i)){
            printf("0");
            return 0;
        }
    }   
    if (n > 44730 || n * n > b){
        if (a <= n && n <= b){
            printf("1");
        }
        else{
            printf("0");
        }
        return 0;
    }
    for(i = 2; i * i <= n; i++){
        if (pp[i])
            continue;
        for(j = i * i; j <= n; j += i){
            pp[j] = 1;
        }
    }
    for(i = 2; i < n; i++){
        if (pp[i])
            continue;
        pr[top++] = i;
    }

    b /= n;
    a = (a  + n - 1) / n;

    if (n > 90){        
        for(i = 0; i < top; i++){
            for(j = pr[i]; j <= b; j += pr[i]){
                p[j] = 1;
            }
        }
        ans = 0;
        for(i = a; i <= b; i++){
            if (!p[i]){
                ans++;
            }
        }
        printf("%d", ans);
        return 0;
    }

    ans = calc(b) - calc(a - 1);
    printf("%d", ans);
    
}