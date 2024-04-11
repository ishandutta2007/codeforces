#include<bits/stdc++.h>

const int N = 1010;
typedef std::pair <int, int> pii;

int x[N], y[N];
int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; ++ i){
        std::multiset <pii> set;
        int ansx = a[1] + x[i], ansy = b[1] + y[i];
        for (int j = 1; j <= n; ++ j){
            if (i == j) continue;
            set.insert({x[j], y[j]});
        }
        bool flag = true;
        for (int j = 2; j <= n; ++ j){
            int xx = ansx - a[j], yy = ansy - b[j];
            auto u = set.find({xx, yy});
            if (u == set.end()){
                flag = false;
                break;
            }
            set.erase(u);
        }
        if (flag){
            printf("%d %d\n", ansx, ansy);
        }
    }
    return 0;
}