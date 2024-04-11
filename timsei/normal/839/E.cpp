#include<bits/stdc++.h>
using namespace std;

const int N = 41;
int n , a[N] ,G[N][N] , cnt , b[N] , c;
double k , ans , p;

int main() {
    cin>>n>>k;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            scanf("%d",&G[i][j]);
        }
    }
    for(int i = 1;i <= n;i ++) a[i] = i;
    int t = 10000;
    while(t --) {
        random_shuffle(a + 1 , a+ n + 1);
        c = 0;
        b[++ c] = a[1];
        for(int i = 2;i <= n;i ++) {
            bool flag = 0;
            for(int j = 1;j <= c;j ++) {
                if(!G[a[i]][b[j]]) {
                    flag = 1;break;
                } 
            }
            if(!flag) b[++c] = a[i];
        }
        cnt = max(cnt , c);
    }
    p = k /(double)cnt;
    ans = p * p * (cnt) * (cnt - 1) / 2.0;
    printf("%.10lf\n",ans);
}