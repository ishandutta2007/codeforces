#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll q, i, l, r, a, b;

int main(){
        for(scanf("%lld",&q);q;q--){
                scanf("%lld%lld",&l,&r);
                if(r%2==0) b = r/2;
                else b = -(r+1)/2;
                if((l-1)%2==0) a = (l-1)/2;
                else a = -l/2;
                printf("%lld\n",b-a);
        }
        return 0;
}