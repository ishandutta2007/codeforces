#include<bits/stdc++.h>
using namespace std;
#define ui unsigned int 
const int N = 1e3+9;
int n,p,q;
ui C[N],ok[N];
ui gcd(ui x,ui y){if(!y) return x;return gcd(y,x%y);}

int main(){
    scanf("%d%d%d",&n,&p,&q);
    p=min(p,n-1);
    C[0]=1,C[1]=n;
    for(int i=2;i<=p;i++){
        for(int j=1;j<=i;j++) ok[j]=(n-j+1);
        for(int j=2;j<=i;j++){
            ui t=j;
            for(int k=1;k<=i;k++){
                ui e=gcd(t,ok[k]);
                t/=e,ok[k]/=e;
            }
        }
        C[i]=1;
        for(int j=1;j<=i;j++) C[i]*=ok[j];
    }
    ui ans=0;
    for(int t=1;t<=q;t++){
        ui R=0,qq=1;
        for(int i=0;i<=p;i++){
            R+=C[i]*qq;
            qq*=t;
        }
        ans^=(t*R);
    }
    printf("%u\n",ans);
    return 0;
}