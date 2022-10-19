#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

char x[N] , y[N] , z[N];

int main() {
    scanf("%s",x);
    scanf("%s",y);
    int l = strlen(x);
    for(int i = 0;i <l;i ++) if(x[i] < y[i]) {
        puts("-1");return 0;
    }
    puts(y);
}