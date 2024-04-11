#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define int long long

const int N = 1000005;
const int M = N;

int a[N] , n , m , t , b[N];

bool pd(int x) {
    for(int i = 1;i <= n;i ++) b[i] = a[i];
    for(int i = 1 , now = 1;i <= m;i ++) {
        int ithas = x - now;
        if(now == n + 1) break;
        while(now <= n && ithas > 0) {
            int tmp = min(b[now] , ithas);
            b[now] -= tmp; ithas -= tmp;
            if(!ithas) break;
            else {
                ithas --;
                now ++;
            }
            if(now == n + 1) break;
        } 
    }
    for(int i = 1;i <= n;i ++) if(b[i]) return 0;
    return 1;
}

signed main() {
    int ans = 0;
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
    while(!a[n] && n) n --;
    if(!n) {
        puts("0");
        return 0;
    }
    int l = 0 ,r = 1e18;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(pd(mid)) {
            ans = mid; r = mid -1;
        }
        else l = mid + 1;
    }
    cout<<ans<<endl;
}