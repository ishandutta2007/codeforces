#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,k,a[N],b[N],ans=0;
int main(){
    scanf("%i%i",&n,&k);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),b[i]=a[i];
    for(int i=0;i<n-1;i++)b[i+1]+=max(0,k-(b[i]+b[i+1]));
    for(int i=0;i<n;i++)ans+=b[i]-a[i];
    printf("%i\n",ans);
    for(int i=0;i<n;i++)printf("%i ",b[i]);
}