#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int grid[10][10];

int main() {
    for (int i=0;i<10;i++) grid[i][0] = 1;
    for (int i=0;i<10;i++) grid[0][i] = 1;
    for (int i=1;i<10;i++) for (int j=1;j<10;j++) grid[i][j] = grid[i-1][j]+grid[i][j-1];
    int n;
    scanf("%d",&n);
    printf("%d\n",grid[n-1][n-1]);

    return 0;
}