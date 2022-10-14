#include <bits/stdc++.h>
using namespace std;
const int N=10050;
char s[N];
int main(){
    scanf("%s",&s);
    int n=strlen(s),m;
    scanf("%i",&m);
    while(m--){
        int l,r,k;
        scanf("%i %i %i",&l,&r,&k);
        l--,r--;
        int sz=r-l+1;
        char b[N];
        for(int i=0;i<n;i++)b[i]=s[i];
        for(int i=l;i<=r;i++){
            int ind=i-l,pos=(ind+k)%sz+l;
            b[pos]=s[i];
        }
        for(int i=0;i<n;i++)s[i]=b[i];
    }
    printf("%s",s);
    return 0;
}