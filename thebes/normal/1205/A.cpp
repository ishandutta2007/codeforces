#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 1e5+5;
int n, i, a[2*MN];

int main(){
    scanf("%d",&n);
    if(n&1){
        printf("YES\n");
        for(i=1;i<=n;i++){
            a[i] = 2*i-1; a[i+n] = 2*i;
            if(i&1) swap(a[i],a[i+n]);
        }
        for(i=1;i<=2*n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}