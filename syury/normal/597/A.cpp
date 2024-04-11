#include<cstdio>
#include<cstdlib>

using namespace std;
typedef long long int lint;

lint k, a, b;

int main(){
    scanf("%lld%lld%lld", &k, &a, &b);
    lint l = a/k + 1, r = b/k;
    if(a % k == 0 || a < 0){l--;}
    if(b < 0 && b % k != 0){r--;}
    printf("%lld", (l > r) ? 0 : (r - l + 1));
    return 0;
}