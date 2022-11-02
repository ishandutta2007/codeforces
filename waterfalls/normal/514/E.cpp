#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,x;
int counts[101];
int dp[101];
vector<vector<int> > A;
vector<vector<int> > B;
vector<vector<int> > ans;
vector<vector<int> > tmp;
int MOD = 1000000007;

void mult(vector<vector<int> >& mat1, vector<vector<int> >& mat2, vector<vector<int> >& dest) {
	tmp.clear();
	for (int i=0;i<mat1.size();i++) tmp.push_back(vector<int>(mat2[0].size()));
	for (int i=0;i<mat1.size();i++) for (int j=0;j<mat2[0].size();j++) for (int k=0;k<mat1[0].size();k++) {
		tmp[i][j] = (tmp[i][j]+(long long) mat1[i][k]*mat2[k][j])%MOD;
	}
	swap(tmp,dest);
}

int main() {
    scanf("%d%d",&n,&x);
    for (int i=0;i<n;i++) {
        int d;
        scanf("%d",&d);
        counts[d]+=1;
    }
    dp[0] = 1;
    for (int i=1;i<=100;i++) for (int j=0;j<i;j++) dp[i] = (dp[i]+(long long) counts[i-j]*dp[j])%MOD;
    if (x<=100) {
        int tot = 0;
        for (int i=0;i<=x;i++) tot = (tot+dp[i])%MOD;
        printf("%d\n",tot);
        return 0;
    }
    x-=100;
    A.push_back(vector<int>(101));
    for (int i=0;i<100;i++) A[0][i] = dp[i+1];
    int tot = 0;
    for (int i=0;i<=100;i++) tot = (tot+dp[i])%MOD;
    A[0][100] = tot;
    for (int i=0;i<101;i++) B.push_back(vector<int>(101));
    for (int i=1;i<100;i++) B[i][i-1] = 1;
    B[100][100] = 1;
    for (int i=0;i<100;i++) B[i][99] = B[i][100] = counts[100-i];
    for (int i=0;i<101;i++) ans.push_back(vector<int>(101));
    for (int i=0;i<101;i++) ans[i][i] = 1;
    for (int i=0;i<30;i++) {
        if (x&(1<<i)) mult(B,ans,ans);
        mult(B,B,B);
    }
    mult(A,ans,A);
    printf("%d\n",A[0][100]);

    return 0;
}