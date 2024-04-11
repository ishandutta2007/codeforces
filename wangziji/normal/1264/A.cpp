#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)
using namespace std;
const int N = 4e5 + 9, M = 1e6 + 9;
int cnt, n, a[N], sum[M], s[N];
int main(){
    int T; scanf("%d", &T);
    while(T--){
        scanf("%d", &n); 
        int cnt = 0, pl; ll x = 0, y = 0, z = 0;
        bool ok = false;
        rep(i, 1, n) {
            scanf("%d", &a[i]); sum[a[i]]++;
            if(a[i] != a[i - 1]) s[++cnt] = a[i];
        }
        if(cnt < 3) { printf("0 0 0\n");rep(i, 1, n) sum[a[i]]--; continue; }
        x = sum[s[1]];
        rep(i, 2, cnt) {
            y += sum[s[i]], pl = i;
            if(x + y > n / 2) { x = y = 0; break; }
            if(y > x) break;
        }
        //cout << pl << endl;
        rep(i, pl + 1, cnt){
            z += sum[s[i]], ok = ok || (z > x && x + y + z <= n / 2);
            //cout << i << " " << x << " " << y << " " << z << endl;
            if(x + y + z > n / 2) { 
                if(!ok) x = y = z = 0; 
                else z -= sum[s[i]];
                break; 
            }
        }
        if(ok) printf("%lld %lld %lld\n", x, y, x ? z : 0);
        else printf("0 0 0\n");
        rep(i, 1, n) sum[a[i]]--;
    }
    return 0;
}