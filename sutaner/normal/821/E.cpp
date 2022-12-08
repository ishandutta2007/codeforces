#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxm 25
#define M 1000000007
#define LL long long int
using namespace std;
struct matrix{
    int r, c;
    LL mat[maxm][maxm];
    matrix(int r, int c):r(r), c(c){memset(mat, 0, sizeof(mat));}
    matrix(){memset(mat, 0, sizeof(mat));}
};
matrix operator * (matrix a, matrix b){
    matrix c = matrix (a.r, b.c);
    for (int i = 0; i < a.r; i++){
        for (int j = 0; j < b.c; j++){
            for (int k = 0; k < a.c; k++){
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j] % M) % M;
            }
        }
    }
    return c;
}
matrix ans = matrix(1,maxm), con = matrix(maxm, maxm);
void fast_power(LL y){
    while(y){
        if (y & 1) ans = ans * con;
        con = con * con;
        y >>= 1;
    }
}
LL n, k;
int main(){
    /*freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);*/
    scanf("%I64d%I64d", &n, &k);
    LL a, b, c;
    ans.mat[0][0] = 1;
    for (int i = 0; i < n; i++){
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        memset(con.mat, 0, sizeof(con.mat));
        if(c){
            con.mat[0][0] = con.mat[1][0] = 1;
            for (int j = 1; j < c; j++){
                con.mat[j - 1][j] = con.mat[j][j] = con.mat[j + 1][j] = 1;
            }
            con.mat[c - 1][c] = con.mat[c][c] = 1;
        }
        else con.mat[0][0] = 1;
        if (i == n - 1) fast_power(k - a);
        else fast_power(b - a);
    }
    printf("%I64d", ans.mat[0][0]);
    return 0;
}