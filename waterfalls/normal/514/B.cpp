#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,x0,y0;
int x[1000],y[1000];

int main() {
    scanf("%d%d%d",&n,&x0,&y0);
    int ans = 0;
    for (int i=0;i<n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        x[i]-=x0; y[i]-=y0;
        int found = 0;
        for (int j=0;j<i;j++) {
            if ((x[i]==x[j] && x[i]==0) || (y[i]==y[j] && y[i]==0)) found = 1;
            else if (x[i]!=0 && x[j]!=0 && x[i]*y[j]==x[j]*y[i]) found = 1;
        }
        ans+=1-found;
    }
    printf("%d\n",ans);

    return 0;
}