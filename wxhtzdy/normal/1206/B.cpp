#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    long long cnt=0,ans=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(a[i]>0)ans+=a[i]-1,a[i]=1,c1++;
        else{
            if(a[i]<0)ans+=abs(a[i])-1,a[i]=-1,c2++;
            else cnt++;
        }
    }
    if(cnt>0){
        ans+=cnt;
    }else{
        ans+=c2%2!=0?2:0;
    }
    printf("%lld",ans);
}