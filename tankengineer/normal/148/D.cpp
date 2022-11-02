#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1005;
bool vis[N][N][2];
double win[N][N][2];

double solve(int w, int b, int first) {
    if (vis[w][b][first]) {
        return win[w][b][first];
    }
    vis[w][b][first] = true;
    if (w == 0) {
        win[w][b][first] = 0;
    } else if (first == 0) {
        if (b == 0) {
            win[w][b][first] = 1;
        } else {
            double p = (double)w / (w + b);
            win[w][b][first] = p + (1 - p) * solve(w, b - 1, 1);
        }
    } else {
        if (b == 0) {
            win[w][b][first] = 0;
        } else {
            double p = (double)b / (w + b);
            if (b == 1) {
                win[w][b][first] = p;
            } else {
                win[w][b][first] = p * (solve(w - 1, b - 1, 0) * w / (w + b - 1) + solve(w, b - 2, 0) * (b - 1) / (w + b - 1));
            }
        }
    }
    return win[w][b][first];
}

int main() {
    int w, b;
    scanf("%d%d", &w, &b);
    printf("%.12f\n", solve(w, b, 0));
    return 0;
}