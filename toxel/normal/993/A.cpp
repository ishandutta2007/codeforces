#include<bits/stdc++.h>

int main(){
    int x1[4], y1[4], x2[4], y2[4];
    int maxx = INT_MIN, minx = INT_MAX, maxy = INT_MIN, miny = INT_MAX;
    for (int i = 0; i < 4; ++ i){
        scanf("%d%d", &x1[i], &y1[i]);
        maxx = std::max(x1[i], maxx);
        minx = std::min(x1[i], minx);
        maxy = std::max(y1[i], maxy);
        miny = std::min(y1[i], miny);
    }
    int maxx1 = INT_MIN, minx1 = INT_MAX, maxy1 = INT_MIN, miny1 = INT_MAX;
    for (int i = 0; i < 4; ++ i){
        scanf("%d%d", &x2[i], &y2[i]);
        maxx1 = std::max(x2[i], maxx1);
        minx1 = std::min(x2[i], minx1);
        maxy1 = std::max(y2[i], maxy1);
        miny1 = std::min(y2[i], miny1);
    }
    if (minx1 > maxx || maxx1 < minx || miny1 > maxy || maxy1 < miny){
        puts("NO");
        return 0;
    }
    for (int i = 0; i < 4; ++ i){
        int tmp1 = x1[i] + y1[i];
        int tmp2 = x1[i] - y1[i];
        x1[i] = tmp1;
        y1[i] = tmp2;
        tmp1 = x2[i] + y2[i];
        tmp2 = x2[i] - y2[i];
        x2[i] = tmp1;
        y2[i] = tmp2;
    }
    maxx = INT_MIN, minx = INT_MAX, maxy = INT_MIN, miny = INT_MAX;
    for (int i = 0; i < 4; ++ i){
        maxx = std::max(x1[i], maxx);
        minx = std::min(x1[i], minx);
        maxy = std::max(y1[i], maxy);
        miny = std::min(y1[i], miny);
    }
    maxx1 = INT_MIN, minx1 = INT_MAX, maxy1 = INT_MIN, miny1 = INT_MAX;
    for (int i = 0; i < 4; ++ i){
        maxx1 = std::max(x2[i], maxx1);
        minx1 = std::min(x2[i], minx1);
        maxy1 = std::max(y2[i], maxy1);
        miny1 = std::min(y2[i], miny1);
    }
    if (minx > maxx1 || maxx < minx1 || miny > maxy1 || maxy < miny1){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}