#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e4+5;
int T, N, i, j, p[4*MN]; ll ans;

int main(){
    scanf("%d",&T);
    p[1] = 1;
    for(i=2;i<4*MN;i++){
        if(p[i]) continue;
        for(j=2*i;j<4*MN;j+=i) p[j] = 1;
    }
    while(T--){
        scanf("%d",&N);
        ans = 1LL*(N+1)*(N+1)*(N+1);
        i = N+1;
        while(p[i]) i++;
        j = i+N;
        while(p[j]) j++;
        ans = min(ans, 1LL*i*j);
        printf("%lld\n",ans);
    }
    return 0;
}