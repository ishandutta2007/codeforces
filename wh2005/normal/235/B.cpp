#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
#define db double 
int n;
db p1[N],f[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        db p;scanf("%lf",&p);
        p1[i]=p*(p1[i-1]+1);
        f[i]=f[i-1]+p*(1+2*p1[i-1]);
    }
    printf("%.15lf\n",f[n]);
    return 0;
}