#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int n,k,t;
    scanf("%i%i%i",&n,&k,&t);
    int r=t/k;
    if(t<=k)printf("%i",t);
    else{
        if(t<=n)printf("%i",k);
        else printf("%i",k-(t-n));
    }
}