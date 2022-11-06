#include<cstdio>
#include<algorithm>

using namespace std;

short d[10001][10001];
struct Q{
    int l, r, x;
    bool operator<(const Q &A) const{ return l<A.l;}
} in[10001];
int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=1; i<=q; i++) scanf("%d%d%d", &in[i].l, &in[i].r, &in[i].x);
    sort(in+1, in+n+1);
    for(int j=1; j<=n; j++) d[0][j] = -1;
    d[0][0] = n+1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            d[i][j] = d[i-1][j];
            if(j-in[i].x >= 0 && d[i-1][j-in[i].x] >= in[i].l){
                short e = in[i].r;
                if(e > d[i-1][j-in[i].x]) e = d[i-1][j-in[i].x];
                if(e > d[i][j]) d[i][j] = e;
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) if(d[n][i] != -1) cnt++;
    printf("%d\n", cnt);
    for(int i=1; i<=n; i++) if(d[n][i] != -1) printf("%d ", i);
    return 0;
}