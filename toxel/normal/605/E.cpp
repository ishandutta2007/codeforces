#include<bits/stdc++.h>

const double eps = 1e-9;
const int N = 1010;

int sig(double p){return (p > eps) - (p < -eps);}

int p[N][N];
double dis[N], prob[N], pre[N];
bool vis[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 1; i <= n; ++ i){
        prob[i] = 1;
    }
    for (int i = 0; i < n; ++ i){
        double min = 1e100;
        int sit;
        if (!i){
            sit = n;
        }
        else{
            for (int j = 1; j <= n; ++ j){
                if (!vis[j] && min > dis[j]){
                    min = dis[j];
                    sit = j;
                }
            }
        }
        vis[sit] = true;
        for (int j = 1; j <= n; ++ j){
            if (!vis[j]){
                pre[j] += prob[j] * (1.0 * p[j][sit] / 100) * (dis[sit] + 1);
                prob[j] *= 1 - 1.0 * p[j][sit] / 100;
                dis[j] = sig(1 - prob[j]) ? (prob[j] + pre[j]) / (1 - prob[j]) : 1e100;
            }
        }
    }
    printf("%.10lf\n", dis[1]);
    return 0;
}