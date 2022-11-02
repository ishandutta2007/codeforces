#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 1;
    while (1) {
        if (!n) {
            break;
        }
        --n;
        if (i % m == 0) {
            n++;
        }
        i++;
    }
    printf("%d\n", i - 1);
}