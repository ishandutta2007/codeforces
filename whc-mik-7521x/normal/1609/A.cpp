#include<bits/stdc++.h>
using namespace std;
const int N=20;
typedef long long ll;
typedef long double lb;
int t,n;
long long a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        ll tot=0;
        for(int i=1;i<=n;i++)while(!(a[i]&1))a[i]>>=1,tot++;
        int ma=-1,to=0;
        for(int i=1;i<=n;i++)if(a[i]>ma)ma=a[i],to=i;
        a[to]<<=tot;
        for(int i=1;i<n;i++)a[n]+=a[i];
        printf("%lld\n",a[n]);
    }
    return  0;
}