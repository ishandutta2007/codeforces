#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 61;
long long n, k, w[N], ow[N];

long long tmp[N];

long long gethead(long long val, int lv) {
    return val & (~((1LL << lv) - 1));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 2; i <= n; i++){
        int par;
        cin >> par >> w[i];
        w[i] ^= w[par];
    }
    sort(w + 1, w + n + 1);
    for(int i = 1; i <= n; i++) ow[i] = w[i];
    //for(int i = 1; i <= n; i++) cout << ow[i] << " "; cout <<'\n';

    long long ans = 0;
    for(int i = M; i >= 0; i--){
        long long way = 0;
        for(int j = 1, L = 1, R = 1; j <= n; j++){
            long long raL = gethead(w[j], i);
            //cout << raL << " \n"[j==n];
            long long raR = raL + (1LL << i);
            while (L <= n && ow[L] < raL) L++;
            while (R <= n && ow[R] < raR) R++;
            way += R - L;
        }
        //cout << way << " " << k << '\n';

        if (way < k) {
            k -= way;
            //ans += 1LL << i;
            for(int j = 1; j <= n; j++) tmp[j] = w[j] ^ (1LL << i);
            for(int en = 1; en <= n; ){
                int st = en;
                while (en <= n && gethead(w[en], i + 1)  == gethead(w[st], i + 1)) en++;
                int mid = st;
                while (mid < en && ((w[mid] >> i) & 1) == ((w[st] >> i) & 1))  mid++;
                
                for(int j = mid; j < en; j++) w[j - mid + st] = tmp[j];
                for(int j = st; j < mid; j++) w[j + (en - mid)] = tmp[j];
            }
            ans += 1LL << i;
        }
    }
    cout << ans;
}