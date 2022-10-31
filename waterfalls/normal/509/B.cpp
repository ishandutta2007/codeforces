#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int a[100];
vector<int> colors[100];

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int color = 1;
    int ok = 1;
    while (true) {
        int toColor = 100000;
        for (int i=0;i<n;i++) toColor = min(toColor,a[i]+1);
        int change = 0;
        for (int i=0;i<n;i++) {
            if (a[i]!=0) change = 1;
            for (int j=0;j<min(toColor,a[i]);j++) colors[i].push_back(color);
            a[i] = max(a[i]-toColor,0);
        }
        if (change) color+=1;
        else break;
    }
    for (int i=0;i<n;i++) if (a[i]!=0) ok = 0;
    if (color-1>k || !ok) printf("NO\n");
    else {
        printf("YES\n");
        for (int i=0;i<n;i++) {
            for (int j=0;j<colors[i].size();j++) printf("%d ",colors[i][j]);
            printf("\n");
        }
    }

    return 0;
}