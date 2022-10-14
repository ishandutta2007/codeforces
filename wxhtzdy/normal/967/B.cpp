#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    scanf("%i%i%i",&n,&a,&b);
    int s[n],sum=0;
    for(int i=0;i<n;i++)scanf("%i",&s[i]),sum+=s[i];
    int h[n];
    for(int i=1;i<n;i++)h[i-1]=s[i];
    sort(h,h+n-1);
    reverse(h,h+n-1);
    int j=0;
    for(int i=0;i<n;i++){
        int k=s[0]*a/sum;
        if(k>=b){printf("%i",i);return 0;}
        sum-=h[j];
        j++;
    }
}