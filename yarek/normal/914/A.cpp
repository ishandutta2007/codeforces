#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans = -1000000;
    while(n--){
        int a;
        scanf("%d", &a);
        bool ok = true;
        if(a >= 0)
        {
            int y = sqrt(a) + 0.0001;
            if(y * y == a) ok = false;
        }
        if(ok) ans = max(ans, a);
    }
    printf("%d\n", ans);
}