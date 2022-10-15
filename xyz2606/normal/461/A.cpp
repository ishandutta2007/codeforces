#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[333333];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i(1); i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    long long ans(0);
    for(int i(1); i <= n; i++) {
        ans = ans + (long long)min(i + 1, n) * a[i];
    }
    cout << ans << endl;
    fclose(stdin);
    return 0;
}