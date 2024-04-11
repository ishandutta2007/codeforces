#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int cur;

class Matrix {
private:
    int r,c;
    vector<vector<int> > mat;
public:
    Matrix(int row, int col) {
        r = row, c = col;
        for (int i=0;i<r;i++) mat.push_back(vector<int>(c));
    }
    int rows() { return r; }
    int cols() { return c; }
    vector<int>& operator[](int x) { return mat[x]; }
    void clear() { for (int i=0;i<r;i++) for (int j=0;j<c;j++) mat[i][j] = 0; }
    bool identity() {
        if (r!=c) return false;
        for (int i=0;i<r;i++) for (int j=0;j<c;j++) mat[i][j] = (i==j) ? 1 : 0;
        return true;
    }
    void operator*=(Matrix other) {
        if (other.rows()!=c) return;
        vector<vector<int> > tmp;
        for (int i=0;i<r;i++) tmp.push_back(vector<int>(other.cols()));
        for (int i=cur;i<r;i++) for (int j=cur;j<other.cols();j++) for (int k=cur;k<c;k++) {
            tmp[i][j] = (tmp[i][j]+(long long) mat[i][k]*other[k][j])%MOD;
        }
        swap(mat,tmp);
    }
    Matrix pow(int p) {
        if (r!=c) return Matrix(0,0);
        Matrix ans(r,c);
        ans.identity();
        Matrix cur(r,c);
        for (int i=0;i<r;i++) for (int j=0;j<c;j++) cur[i][j] = mat[i][j];
        for (int i=0;i<=30;i++) {
            if (p<(1<<i)) break;
            if (p&(1<<i)) ans*=cur;
            cur*=cur;
        }
        return ans;
    }
};

int ways[128][128][8];
int w[7];

int main() {
    for (int i=0;i<128;i++) for (int j=0;j<128;j++) {
        ways[i][j][0] = 1;
        for (int k=1;k<=7;k++) {
            if ((i&j&(1<<(k-1)))==0) ways[i][j][k] = (ways[i][j][k]+ways[i][j][k-1])%MOD;
            for (int l=k-2;l>=0;l--) ways[i][j][k] = (ways[i][j][k]+ways[i][j][l])%MOD;
        }
    }
    for (int i=0;i<7;i++) scanf("%d",&w[i]);
    Matrix A(1,128);
    A[0][127] = 1;
    Matrix B(128,128);
    for (int i=7;i>0;i--) {
        if (w[i-1]==0) continue;
        B.clear();
        cur = 0;
        for (int j=7;j>i;j--) cur+=1<<(j-1);
        for (int j=cur;j<128;j++) for (int k=cur;k<128;k++) B[j][k] = ways[j][k][i];
        B = B.pow(w[i-1]);
        cur = 0;
        A*=B;
    }
    printf("%d\n",A[0][127]);

    return 0;
}