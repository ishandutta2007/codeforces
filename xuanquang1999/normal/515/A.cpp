#include<bits/stdc++.h>
int main() {
    int x, y, s;
    scanf("%d%d%d", &x, &y, &s);
    puts(((abs(x)+abs(y)-s)%2 == 0 && abs(x)+abs(y) <= s) ? "Yes" : "No");
}