#include<bits/stdc++.h>
using namespace std;
const int N = 409;
int n,a[N];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int cnt1=1,cnt2=0,num=a[i]-1,t;
            for(int k=i+1;k<=j;k++)
                cnt1+=(num/a[k]),num%=a[k];
            t=num=a[i]-1-num+a[j];
            for(int k=1;k<=n;k++)
                cnt2+=(num/a[k]),num%=a[k];
            if(cnt1<cnt2&&(ans==-1||ans>t)) ans=t;
        }
    }
    printf("%d\n",ans);
    return 0;
}