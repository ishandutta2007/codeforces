#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char grid[101];

int main() {
    scanf("%d %s",&n,&grid);
    int ok = 0;
    for (int i=0;i<n;i++) {
        if (grid[i]=='.') continue;
        for (int l=1;l<50;l++) {
            if (i+4*l<100 && grid[i+l]=='*' && grid[i+2*l]=='*' && grid[i+3*l]=='*' && grid[i+4*l]=='*') ok = 1;
        }
    }
    if (ok) printf("yes\n");
    else printf("no\n");

    return 0;
}