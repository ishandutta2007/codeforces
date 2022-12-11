#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,a[N];
int main(){
    scanf("%d",&n);
    int kk=1;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    while(kk<n)kk<<=1;
    for(int i=0;1<<i<=kk;i++){
        for(int o=0;o<n;o++){
            if(o>>i&1)a[o]^=a[o^(1<<i)];
        }
    }
    for(int i=0;1<<i<=kk;i++){
        for(int o=0;o<n;o++){
            if((o>>i&1)^1)a[o]^=a[o^(1<<i)];
        }
    }
    for(int i=n-1;~i;i--)printf("%d ",a[i]);
    return 0;
}