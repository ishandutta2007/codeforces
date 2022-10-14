#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n,x;scanf("%i %i",&n,&x);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        sort(a,a+n);
        reverse(a,a+n);
        long long sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum/(i+1)>=(long long)x)ans++;
        }
        printf("%i\n",ans);
    }
    return 0;
}