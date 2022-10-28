#include<stdio.h>
int sum(int a[],int n){
    int i,x=0;
    for (i=0;i<n;i++){
        x=x+a[i];
    }
    return x;
}
int mod(int e){
    if (e>0) return e;
    else return -e;
}
int main(){
    int n,x,y,ans=0,i,s;
    float j=0;
    scanf("%d",&n);
    int a[n],b[n],bty[n+1];
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    x=sum(a,n);
    y=sum(b,n);
    bty[0]=x-y;
    if(bty[0]<0) bty[0] = -bty[0];
    s = bty[0];
    for(i=0;i<n;i++){
        if(x>y){
            bty[i+1]=bty[0] - 2*a[i] + 2*b[i]; 
            bty[i+1] = mod(bty[i+1]);
        }
        if(y>x){
            bty[i+1]=bty[0] - 2*b[i] + 2*a[i]; 
            bty[i+1] = mod(bty[i+1]);
        }
        if (bty[i+1]>s) {
            s = bty[i+1];
            ans = i+1;}
    }
    printf("%d",ans);
}