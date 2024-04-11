#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int p[n];
    for(int i=0;i<n;i++){
        if(i==0)p[i]=-1;
        else{
            if(a[i]==a[i-1])p[i]=p[i-1];
            else p[i]=i-1;
        }
    }
    while(m--){
        int l,r,x;
        scanf("%i %i %i",&l,&r,&x);
        --l,--r;
        if(a[r]!=x)printf("%i\n",r+1);
        else{
            if(p[r]>=l)printf("%i\n",p[r]+1);
            else printf("-1\n");
        }
    }
    return 0;
}