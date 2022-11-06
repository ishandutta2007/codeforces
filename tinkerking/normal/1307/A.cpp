#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N, a[110], D;

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&D);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        }
        for (int i=2;i<=N;i++) {
            while(a[i] > 0) {
                if ((i - 1) > D) break;
                D -= (i - 1);
                a[i]--;
                a[1]++;
            }            
        }
        printf("%d\n",a[1]);
    }
}