#include <bits/stdc++.h>
using namespace std;
const int N=300050;
char s[N];
int main(){
    int n,x,y;scanf("%i%i%i",&n,&x,&y);
    scanf("%s",s+1);
    int cnt=0;
    for(int i=1;i<=n;i++)if((i==1||s[i-1]=='1')&&s[i]=='0')cnt++;
    if(cnt==0)return 0*printf("0");
    printf("%lld",min(cnt*1LL*y,y+(cnt-1)*1LL*x));
    return 0;
}