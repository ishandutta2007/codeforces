#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(4444);
struct RecA {
    int v, d, p, i;
} a[N];
int main() {
    int n;
    scanf("%d", &n);
    for(int i(1); i <= n; i++) {
        scanf("%d%d%d", &a[i].v, &a[i].d, &a[i].p);
        a[i].i = i;
    }
    vector<int> ans;
    while(n >= 1) {
        ans.push_back(a[1].i);
        for(int i(2); i <= n; i++) {
            a[i].p -= max(0, a[1].v - i + 2);
            if(a[i].p < 0) {
                a[i].p = -1;
            }
        }
        for(int i(1); i < n; i++) {
            a[i] = a[i + 1];
        }
        n--;
        for(;;) {
            int I(-1);
            for(int i(1); i <= n; i++) {
                if(a[i].p < 0) {
                    I = i;
                    break;
                }
            }
            if(I == -1) {
                break;
            }
            for(int i(I + 1); i <= n; i++) {
                a[i].p -= a[I].d;
                if(a[i].p < 0) {
                    a[i].p = -1;
                }
            }
            for(int i(I); i < n; i++) {
                a[i] = a[i + 1];
            }
            n--;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i(0); i < (int)ans.size(); i++) {
        printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
    }
}