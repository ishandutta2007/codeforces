#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> a[5555];
int main() {
    int n;
    scanf("%d", &n);
    for(int i(1); i <= n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    int now(-1e9);
    sort(a + 1, a + 1 + n);
    for(int i(1); i <= n; i++) {
        if(a[i].second >= now) {
            now = a[i].second;
        }else {
            now = a[i].first;
        }
    }
    printf("%d\n", now);
}