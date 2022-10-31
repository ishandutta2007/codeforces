
#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,arr[100000];
int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",arr+i);

        lli a=0,b=0;
        for(int i=0;i<n;i++) a+=arr[i],b^=arr[i];
        
        printf("2\n");
        printf("%lld %lld\n",b, a+b);
    }
    return 0;
}