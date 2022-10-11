#include <algorithm>
#include <cstdio>

using namespace std;


int l[1005];
int d[1005];

int main() {
int n;
scanf("%d", &n);
for(int i = 0; i < n; i++) {
scanf("%d", &l[i]);
}
for(int i = 0; i < n-1; i++) {
    d[i] = l[i] - l[i+1];
}
int stage = 0;
// 0 is dec
// 1 is con
// 2 is inc
for(int i = 0; i < n-1; i++) {
    if(d[i] < 0 && stage > 0)     {
        printf("NO\n");
        return 0;
    }
    if(d[i] == 0 && stage > 1) {
        printf("NO\n");
        return 0;
    }
    if(d[i] > 0) stage = 2;
    else if(d[i] == 0) stage = 1;
    else stage = 0;
}
printf("YES\n");

return 0;
}