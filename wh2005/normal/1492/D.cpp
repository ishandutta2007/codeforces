#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int a,b,k;
int x[N],y[N];

int main(){
    scanf("%d%d%d",&a,&b,&k);
    int len=a+b;
    if(a==0){
        if(k==0){
            printf("Yes\n");
            for(int i=1;i<=len;i++) printf("1");puts("");
            for(int i=1;i<=len;i++) printf("1");puts("");
        }
        else printf("No\n");
        return 0;
    }
    if(b==1){
        if(k==0){
            printf("Yes\n");
            x[1]=y[1]=1;
            for(int i=1;i<=len;i++) printf("%d",x[i]);puts("");
            for(int i=1;i<=len;i++) printf("%d",y[i]);puts("");
        }
        else printf("No\n");
        return 0;
    }
    if(k>a+b-2){printf("No\n");return 0;}  
    printf("Yes\n");
    x[1]=1,x[2]=1,y[1]=1,y[k+2]=1;
    int nd=b-2;
    for(int i=3;i<=len&&nd;i++){
        if(i==k+2) continue;
        x[i]=1,y[i]=1,nd--;
    }
    for(int i=1;i<=len;i++) printf("%d",x[i]);puts("");
    for(int i=1;i<=len;i++) printf("%d",y[i]);puts("");
    return 0;
}