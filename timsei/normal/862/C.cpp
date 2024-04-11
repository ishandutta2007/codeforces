#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n , m , a[N] , cnt , vis[N];

int main(void) {
    srand(20020705);
    scanf("%d%d",&n,&m);
    int x = m;
    if(n == 0) {
        if(m) puts("NO");
        else puts("YES");
        return 0;
    }
    int p = n % 4;
    if(p == 0) p += 4;
    if(n > p) p += 4;
    for(int i = 1;i <= 100000;i ++) {
        for(int j = 1;j <= p - 1;j ++) {
        	a[j] = rand() % 1000000 + 1;
        	while(vis[a[j]] == i) a[j] = rand() % 1000000 + 1;
        	vis[a[j]] = i;
		}
        int k = x;
        for(int j = 1;j <= p - 1;j ++) k ^= a[j];
        if(vis[k] == i) continue;
        cnt = p;
        a[cnt] = k;
        vis[k] = i;
        for(int j = 0;j <= 1000000 / 4;j ++) {
            bool flag = 0;
            for(int k = 0;k <= 3;k ++) if(vis[j * 4 + k] == i) flag = 1;
            if(!flag) {
                for(int k = 0;k <= 3;k ++) a[++ cnt] = j * 4 + k;
            } 
            if(cnt == n) break;
        }
        if(cnt < n) continue;
        puts("YES");
        sort(a + 1 , a + n + 1);
        for(int j = 1;j <= n;j ++) cout<<a[j]<<" ";
        return 0;
    }
    puts("NO");
}