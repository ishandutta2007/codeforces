//*

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define MN 200000
#define eps (5e-12)

using namespace std;

int A[MN];
int N;
double S[MN];

double get_max(double x){
    double res = 0;
    S[0] = A[0] - x;
    res = S[0];
    for (int i = 1; i < N; i++){
        S[i] = max(S[i - 1] + A[i]-x, A[i]-x);
        if (res < S[i])res = S[i];
    }
    return res;
}

double get_min(double x){
    double res = 1e16;
    S[0] = A[0] - x;
    res = S[0];
    for (int i = 1; i < N; i++){
        S[i] = min(S[i - 1] + A[i] - x, A[i] - x);
        if (res > S[i])res = S[i];
    }
    return res;
}

double get_v(double x){
    return max(get_max(x), abs(get_min(x)));
}

int main(){
//  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &A[i]);
    double l = -10000.0, r = 10000.0, m;
    double ans;
    while (r-l>eps){
        m = (l + r)/2;
        double x = m;
        if (get_max(x) > abs(get_min(x))){
            l = m;
        }
        else{
            r = m;
        }
        ans = m;
    }
    printf("%.10lf\n", get_v(ans));
    return 0;
}

//*/