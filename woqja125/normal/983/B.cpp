#include<cstdio>
#include<algorithm>
using namespace std;
int a[5001];
int b[5001][5001];
int m[5001][5001];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", a+i);
        b[i][i] = a[i];
    }
    for(int d=1; d<n; d++){
        for(int i=1; i+d<=n; i++) b[i][i+d] = b[i][i+d-1] ^ b[i+1][i+d];
    }
    for(int i=1; i<=n; i++)
        m[i][i] = b[i][i];
    for(int d=1; d<n; d++){
        for(int i=1; i+d<=n; i++) m[i][i+d] = max(b[i][i+d], max(m[i][i+d-1], m[i+1][i+d]));
    }
    int q, l, r;
    scanf("%d", &q);
    for(int i=1; i<=q; i++){
        scanf("%d%d", &l, &r);
        printf("%d\n", m[l][r]);
    }
    return 0;
}