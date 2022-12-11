#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k;
char s[N];
int main(){
    scanf("%d%d%d%s",&n,&m,&k,s+1);
    m+=k;
    while(m--){
        int tp,l,r,d;
        scanf("%d%d%d%d",&tp,&l,&r,&d);
        if(tp==1)memset(s+l,d+'0',r-l+1);
        else puts(memcmp(s+l,s+l+d,r-l-d+1)==0?"YES":"NO");
    }
}