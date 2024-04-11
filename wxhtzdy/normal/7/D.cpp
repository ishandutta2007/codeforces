#include <bits/stdc++.h>
using namespace std;
const int N=5000050;
const int base=343;
unsigned long long ans[N],pw=1,hsh[2];
char s[N];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    for(int i=1;i<=n;i++){
        hsh[0]+=s[i-1]*pw;pw*=base;
        hsh[1]=base*hsh[1]+s[i-1];
        if(hsh[0]==hsh[1])ans[i]=ans[i/2]+1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)sum+=ans[i];
    printf("%i",sum);
    return 0;
}