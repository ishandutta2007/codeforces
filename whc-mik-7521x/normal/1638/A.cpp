#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,a[N],t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int pd=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=i){pd=i;break;}
        }
        if(pd){
            int now=0;
            for(int i=1;i<=n;i++)if(a[i]==pd)now=i;
            reverse(a+pd,a+now+1);
        }
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        puts("");
    }
    return  0;
}