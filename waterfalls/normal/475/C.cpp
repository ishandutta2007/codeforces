#include <cstdio>
#include <algorithm>

using namespace std;

int painting[1001][1001];
int draw[1001][1001];
int n,m;

int check(int flip) {
    if (flip==0) for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) draw[i][j] = painting[i][j];
    else for (int i=0;i<=m;i++) for (int j=0;j<=n;j++) draw[i][j] = painting[j][i];
    int x,y;
    bool found = false;
    int nums[] = {n,m};
    for (int i=0;i<nums[flip] && !found;i++) {
        for (int j=0;j<nums[1-flip] && !found;j++) {
            if (draw[i][j]==1) {
                x = i;
                y = j;
                found = true;
            }
        }
    }
    int length = 1;
    while (draw[x][y+length]==1) length+=1;
    int height = 1;
    for (int i=0;i<length;i++) draw[x][y+i] = 0;
    bool right = false;
    while (draw[x+height][y]==1 || draw[x][y+length]==1) {
        if (draw[x+height][y]==1 && draw[x][y+length]==1) {
            if (right) return -1;
            height+=1;
            for (int i=0;i<length;i++) {
                if (draw[x+height-1][y+i]==0) return -1;
                draw[x+height-1][y+i] = 0;
            }
        } else if (draw[x+height][y]==1) {
            x+=1;
            for (int i=0;i<length;i++) {
                if (draw[x+height-1][y+i]==0) return -1;
                draw[x+height-1][y+i] = 0;
            }
        } else {
            right = true;
            y+=1;
            for (int i=0;i<height;i++) {
                if (draw[x+i][y+length-1]==0) return -1;
                draw[x+i][y+length-1] = 0;
            }
        }
    }
    bool ok = true;
    for (int i=0;i<nums[flip];i++) for (int j=0;j<nums[1-flip];j++) if (draw[i][j]==1) return -1;
    return length*height;
}

int main() {
    scanf("%d%d",&n,&m);
    char row[1013];
    for (int i=0;i<n;i++) {
        fill(painting[i],painting[i]+m+1,0);
        scanf(" %s",&row);
        for (int j=0;j<m;j++) if (row[j]=='X') painting[i][j] = 1;
    }
    int first = check(0);
    int second = check(1);
    if (first==-1 && second==-1) printf("-1\n");
    else if (first==-1) printf("%d\n",second);
    else if (second==-1) printf("%d\n",first);
    else printf("%d\n",min(first,second));

    return 0;
}