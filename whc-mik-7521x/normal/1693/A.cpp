#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        if(sum!=0)puts("No");
        else{
            int pd=0;
            for(int i=n;i>1;i--){
                if(a[i]>0&&a[i]+sum>=0)pd=1;
                sum+=a[i];
            }
            puts(pd?"No":"Yes");
        }
    }
    return  0;
}