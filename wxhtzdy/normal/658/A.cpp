//1+1=2 2+2=2*2=4
#include<bits/stdc++.h>
using namespace std;
int n,c,a[55],t[55];
int main(){
    scanf("%i%i",&n,&c);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<n;i++)scanf("%i",&t[i]);
    int s=0,x1=0,x2=0;
    for(int i=0;i<n;i++)s+=t[i],x1+=max(0,a[i]-s*c);
    s=0;
    for(int i=n-1;i>=0;i--)s+=t[i],x2+=max(0,a[i]-s*c);
    if(x1==x2)printf("Tie");
    else {
        if(x1>x2)printf("Limak");
        else printf("Radewoosh");
    }
}