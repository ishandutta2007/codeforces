#include <stdio.h>
#define max(x,y) (x>y?x:y)
using namespace std;
char s[100005];
int n,t;
unsigned int f[100005],ans;
int main(){
    scanf("%d\n%s",&n,s);
    if (n&1){puts("0");return 0;}
    f[0]=1;
    for (int i=0;i<n;i++)
        if (s[i]!='?')t++;else
        for (int j=i+1;j>=max(2,i+i-n);j--)f[j]+=f[j-2];
    ans=f[n];for (int i=0;i<n/2-t;i++)ans*=25;
    printf("%u",ans);
}