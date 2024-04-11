#include <bits/stdc++.h>
using namespace std;
#define ldb long double
const int N=100050;
ldb p[N];
ldb mpow(ldb x,int k){
    ldb ans=1;
    for(;k;k>>=1,x*=x)if(k&1)ans*=x;
    return ans;
}
int main(){
    int m,n;scanf("%i%i",&m,&n);
    ldb ans=0;
    for(int i=1;i<=m;i++)p[i]=mpow((ldb)i/m,n);
    for(int i=m;i>=1;i--)ans+=(p[i]-p[i-1])*i;
    cout<<fixed<<setprecision(5)<<ans;
    return 0;
}