#include <cstdio>
#include <algorithm>

using namespace std;

int num[5000013];
int cur[5000013];
int sum[5000013];

int main() {
    for (int i=0;i<5000013;i++) cur[i] = 1;
    for (int i=1;i<5000013;i++) if (cur[i]!=i) {
        num[i]+=1;
        for (int j=i+i;j<5000013;j+=i) num[j]+=1, cur[j]*=i/cur[i];
    }
    for (int i=1;i<5000013;i++) sum[i] = sum[i-1]+num[i];
    int t;
    scanf("%d",&t);
    for (int T=0;T<t;T++) {
        int a,b;
        scanf("%d%d",&b,&a);
        printf("%d\n",sum[b]-sum[a]);
    }

    return 0;
}