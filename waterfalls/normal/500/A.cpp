#include <cstdio>

using namespace std;

int n,t;
int tele[30000];

int main() {
    scanf("%d%d",&n,&t);
    for (int i=0;i<n-1;i++) scanf("%d",&tele[i]);
    int loc = 0;
    while (true) {
        if (loc>=t-1) break;
        if (tele[loc]+loc>=n) break;
        loc = loc+tele[loc];
    }
    if (loc==t-1) printf("YES\n");
    else printf("NO\n");

    return 0;
}