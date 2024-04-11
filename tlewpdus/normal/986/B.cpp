#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000100];
int chk[1000100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&arr[i]);
    int ans = 0;
    for (i=1;i<=n;i++) {
        if (chk[i]) continue;
        int p = i, c = 0;
        do {
            c++;
            chk[p] = 1;
            p = arr[p];
        } while(p!=i);
        ans += c-1;
    }
    puts((ans+n)%2?"Um_nik":"Petr");

    return 0;
}