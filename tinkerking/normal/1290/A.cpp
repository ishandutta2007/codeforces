#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,M,K;
int a[3510],b[3510];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&N,&M,&K);
        for (int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
        } 
        K = min(K, M - 1);
        vector<int>gao;
        for (int i=0;i<=M-1;i++) {
            b[i] = max(a[i + 1], a[N - (M - 1 - i)]);
            //printf("?? %d\n",b[i]);
        }
        int ans = 0;
        int len = M - K;
        //printf("fuck %d\n",len);
        for (int i=0;i<M-len+1;i++) {
            //printf("wow %d\n",i);
            int mi = 1e9;
            for (int j=i;j<i+len;j++) {
                mi = min(mi, b[j]);
            }
            ans = max(ans, mi);
        }
        printf("%d\n",ans);
    }
}