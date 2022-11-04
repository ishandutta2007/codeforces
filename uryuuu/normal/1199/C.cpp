#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 500000;
long long Qpow(int a, int b){
    long long ans = 1, base = a;
    while(b){
        if(b & 1){
            ans *= base;
        }
        base *= base;
        b >>= 1;
    }
    return ans;
}
int main(){
    //freopen("test", "r", stdin);
    ios::sync_with_stdio(false);
    int n, I;
    cin >> n >> I;
    int A[Maxn + 1], B[Maxn + 1];
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
        B[i] = A[i];
    }
    int y = 8 * I / n;
    if(y > 20)
    {
        cout << "0\n";
        return 0;
    }
    long long x = Qpow(2, y);
    sort(B + 1, B + 1 + n);
    int Size = unique(B + 1, B + 1 + n) - (B + 1);
    int cnt[Maxn + 1] = {};
    for(int i = 1; i <= n; ++i){
        int pos = lower_bound(B + 1, B + 1 + Size, A[i]) - (B + 1) + 1;
        ++cnt[pos];
    }
    int Min = 1e9;
    int Sum[Maxn + 1] = {};
    for(int i = 1; i <= Size; ++i){
        Sum[i] = Sum[i - 1] + cnt[i];
    }
    for(long long i = 1; i <= Size && i + x <= Size; ++i){
        Min = min(Min, n - (Sum[i + x] - Sum[i]));
    }
    if(Min == 1e9){
        cout << "0\n";
    }else
        cout << Min << '\n';
    /*
     for(int i = 1; i <= Size; ++i){
     int sum = 0;
     for(int j = 0; j < x && i + j < n; ++j){
     sum += cnt[i + j];
     }
     Min = min(n - sum, Min);
     }
     */
    return 0;
}