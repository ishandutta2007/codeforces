#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,m,a[N],cnt;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%1d",&a[i]),a[i]+=a[i-1];
        cnt=a[n];
        if(1ll*m*cnt%n!=0)puts("-1");
        else{
            int pd=0;
            for(int i=1;i+m-1<=n;i++){
                if(a[i+m-1]-a[i-1]==1ll*m*cnt/n){
                    pd=1;
                    printf("%d\n%d %d\n",1,i,i+m-1);
                    break;
                }
            }
            if(!pd){
                for(int i=1;i<m;i++){
                    if(a[i]+a[n]-a[n-(m-i)]==1ll*m*cnt/n){
                        printf("%d\n%d %d\n%d %d\n",2,1,i,n-(m-i)+1,n);
                        break;
                    }
                }
            }
        }
    }
    return  0;
}