#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    int a[n+2],b[k+2];
    a[0]=-1e9;
    a[n+1]=2e9;
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    for(int i=1;i<=k;i++)scanf("%i",&b[i]);
    for(int i=0;i<=n+1;i++)a[i]-=i;
    b[0]=0;
    b[k+1]=n+1;
    int ans=0;
    for(int i=0;i<=k;i++){
        int l=b[i],r=b[i+1],sz=r-l-1;
        if(a[l]>a[r]){
            printf("-1");
            return 0;
        }
        vector<int> v;
        for(int j=l+1;j<r;j++){
            if(a[j]>=a[l]&&a[j]<=a[r]){
                auto pos=upper_bound(v.begin(),v.end(),a[j]);
                if(pos==v.end())v.push_back(a[j]);
                else *pos=a[j];
            }
        }
        ans+=sz-(int)v.size();
    }
    printf("%i",ans);
    return 0;
}