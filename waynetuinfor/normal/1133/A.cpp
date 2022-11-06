#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    int x = h1 * 60 + m1;
    int y = h2 * 60 + m2;
    int z = (x + y) / 2;
    printf("%02d:%02d\n", z / 60, z % 60);
}