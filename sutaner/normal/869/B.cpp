#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define LL long long int
using namespace std;

int main(){
    LL a, b;
    scanf("%I64d%I64d", &a, &b);
    LL ans = 1;
    for (LL i = a + 1; i <= b; i++){
        ans *= (i % 10); ans %= 10;
        if (!ans) break;
    }
    printf("%I64d", ans);
    return 0;
}