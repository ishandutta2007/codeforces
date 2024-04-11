#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int n , a[N] , x , y , k , P[N] , st[N] , tot;

int main(void) {
    scanf("%d%d" , &n, &k);
    for(int i = 1;i <= k;++ i) scanf("%d" , &P[i]);
    int Min = 1 , now = 1;
    while(1) {
        if(tot && st[tot] == Min) {
            tot --; ++ Min; continue;
        }
        while(P[now] != Min && now <= k) {
            st[++ tot] = P[now ++];
            if(tot > 1 && st[tot] > st[tot - 1]) {
                puts("-1"); exit(0);
            }
        }
        if(now == k + 1) break;
        ++ now; ++ Min;
    }
    for(int i = 1;i <= k;++ i) printf("%d " ,P[i]);
    for(int i = tot;i >= 1;-- i) {
        for(int j = st[i] - 1;j >= Min;-- j) printf("%d ", j);
        Min = st[i] + 1; 
    }
    for(int j = n;j >= Min;-- j) printf("%d " , j);
}