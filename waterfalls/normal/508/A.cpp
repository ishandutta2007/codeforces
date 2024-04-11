#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,k;
int colored[1002][1002];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    int lost = -1;
    for (int i=0;i<k && lost==-1;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        colored[x][y] = 1;
        if (colored[x][y+1] && colored[x+1][y] && colored[x+1][y+1]) lost = i;
        if (colored[x][y+1] && colored[x-1][y] && colored[x-1][y+1]) lost = i;
        if (colored[x][y-1] && colored[x-1][y] && colored[x-1][y-1]) lost = i;
        if (colored[x][y-1] && colored[x+1][y] && colored[x+1][y-1]) lost = i;
    }
    printf("%d\n",lost+1);
}