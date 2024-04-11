#include <bits/stdc++.h>
using namespace std;
void ckmx(int& a,int b){a=max(a,b);}
const int N=200000;
int h[N],w[N],t[N],sum=0;
int main(){
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i %i",&w[i],&h[i]),sum+=w[i],t[i]=h[i];
    sort(t,t+n);
    for(int i=0;i<n;i++){
        int ans=0;
        if(h[i]==t[n-1])ckmx(ans,(sum-w[i])*t[n-2]);
        else ckmx(ans,(sum-w[i])*t[n-1]);
        printf("%i ",ans);
    }
}