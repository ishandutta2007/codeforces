#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int t,n,a[N][N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=2*n;i++){
            for(int o=1;o<=2*n;o++){
                scanf("%d",&a[i][o]);
                if((i>n&&o>n)||(i<=n&&o<=n))sum+=a[i][o];
            }
        }
        printf("%lld\n",sum+1ll*min(a[n+1][1],min(a[n<<1][1],min(a[n+1][n],min(a[n<<1][n],min(a[1][n+1],min(a[1][n<<1],min(a[n][n+1],a[n][n<<1]))))))));
    }
    return  0;
}