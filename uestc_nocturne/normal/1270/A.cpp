/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

int n, u, v, w, _;
int main() {
    scanf("%d", &_);
    while (_--) {
        bool ok = true;
        scanf("%d%d%d",&n,&u,&v);
        for(int i = 0; i < u; ++i) scanf("%d", &w);
        for(int i = 0; i < v; ++i) {
            scanf("%d", &w);
            if (w == n) ok = false;
        }
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*

*/