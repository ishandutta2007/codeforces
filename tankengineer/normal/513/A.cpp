#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%s\n", a > b ? "First" : "Second");
    return 0;
}