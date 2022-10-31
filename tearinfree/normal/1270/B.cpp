
#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,arr[200001];
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",arr+i);
        
        int idx = 1,f=0;
        for(int i=2;i<=n;i++) {
            if(arr[i] - i > arr[idx] - idx) {
                puts("YES");
                printf("%d %d\n",idx, i);
                f = 1;
                break;
            }
            if(arr[idx] - idx > arr[i] - i) {
                idx = i;
            }
        }
        if(!f) {
            reverse(arr+1,arr+n+1);
            int idx = 1,f=0;
            for(int i=2;i<=n;i++) {
                if(arr[i] - i > arr[idx] - idx) {
                    puts("YES");
                    printf("%d %d\n",n-i+1, n-idx+1);
                    f = 1;
                    break;
                }
                if(arr[idx] - idx > arr[i] - i) {
                    idx = i;
                }
            }
            if(!f) puts("NO");
        }
    }
    return 0;
}