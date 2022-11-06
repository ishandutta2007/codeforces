#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[100001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    std::sort(a+1, a+n+1);
    vector<int> v;
    for(int i=1, j; i<=n; i=j) {
        for(j=i; j<=n && a[i] == a[j]; j++) v.push_back(j-i);
    }
    sort(v.begin(), v.end());
    int m = 0;
    for(int i=1, j=0; i<=n; i++) {
        for(; j<n && v[j] < i; j++);
        if(m < j - i) m = j-i;
    }
    printf("%d\n", m);
    return 0;
}