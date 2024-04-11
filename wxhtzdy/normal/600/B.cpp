#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int a[n],b[m];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<m;i++)scanf("%i",&b[i]);
    sort(a,a+n);
    for(int i=0;i<m;i++){
        int bot=0,top=n-1,ans=-1;
        while(bot<=top){
            int mid=(bot+top)>>1;
            if(a[mid]<=b[i])ans=mid,bot=mid+1;
            else top=mid-1;
        }
        printf("%i ",ans+1);
    }
    return 0;
}