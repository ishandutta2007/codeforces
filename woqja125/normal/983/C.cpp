#include<cstdio>
int dp[2001][10][715];
int a[2001];
int b[2001];
inline int abs(int x){return x>0?x:-x;}
inline int min(int a, int b){return a>b?b:a;}

inline int compswap(int &a, int &b){
    if(a>b){
        int t = a;
        a = b;
        b = t;
    }
}
int find[10000];
int encode(int a, int b, int c, int d){
    compswap(a, b); compswap(b, c); compswap(c, d);
    compswap(a, b); compswap(b, c);
    compswap(a, b);
    return find[a*1000 + b*100 + c*10 + d];
}
int encode(int *t){
    return encode(t[0], t[1], t[2], t[3]);
}
int C = -1;
int H[715][4], tmp[4];
int decode(int N, int *d){
    for(int i=0; i<4; i++) d[i] = H[N][i];
}
void dfs(int x, int m){
    if(x == 4){
        C++;
        int N = 0;
        for(int i=0; i<4; i++){
            H[C][i] = tmp[i];
            N = N*10 + tmp[i];
        }
        find[N] = C;
        return;
    }
    for(int i=m; i<10; i++){
        tmp[x] = i;
        dfs(x+1, i);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%d", a+i, b+i);
    }
    dfs(0, 0);
    //printf("%d\n", C);
    for(int i=0; i<=n; i++) for(int j=1; j<=9; j++) for(int h=0; h<715; h++) dp[i][j][h] = 200000000;
    dp[0][1][0] = 0;
    for(int i=0; i<=n; i++) for(int h=714; h>=0; h--) for(int j=1; j<=9; j++) {
        if(dp[i][j][h] == 200000000) continue;
        int d[4];
        decode(h, d);
        if(i!=n && d[0] == 0){
            d[0] = b[i+1];
            int &dest = dp[i+1][a[i+1]][encode(d)];
            dest = min(dest, abs(a[i+1] - j) + dp[i][j][h]);
            d[0] = 0;
        }
        for(int u=0; u<4; u++){
            if(d[u] == 0) continue;
            int last = d[u];
            d[u] = 0;
            int &dest = dp[i][last][encode(d)];
            dest = min(dest, abs(last - j) + dp[i][j][h]);
            d[u] = last;
        }
    }
    int ans = 200000000;
    for(int j=1; j<=9; j++) if(ans > dp[n][j][0]) ans = dp[n][j][0];
    printf("%d\n", 2*n+ans);
    return 0;
}