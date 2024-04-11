#include <cstdio>
#include <cmath>

using namespace std;

int n;

int expo(int x,int p) {
    int ans = 1;
    int cur = x;
    for (int i=0;i<30;i++) {
        if (p&(1<<i)) ans = ((long long) ans*cur)%n;
        cur = ((long long) cur*cur)%n;
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    if (n==1) printf("YES\n1\n");
    else if (n==4) printf("YES\n1\n3\n2\n4\n");
    else {
        int ok = 1;
        for (int i=2;i<n;i++) if (n%i==0) ok = false;
        if (!ok) printf("NO\n");
        else {
            printf("YES\n1\n");
            for (int i=2;i<n;i++) printf("%d\n",((long long) i*expo(i-1,n-2))%n);
            printf("%d\n",n);
        }
    }

    return 0;
}