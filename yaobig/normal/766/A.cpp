#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long ll;
char a[maxn+5],b[maxn+5];
int main()
{
    int i,l1,l2,ans=-1;
    scanf("%s",a);
    scanf("%s",b);
    l1=strlen(a);
    l2=strlen(b);
    if(l1!=l2) ans=max(l1,l2);
    else if(strcmp(a,b)!=0) ans=l1;
    printf("%d\n",ans);
    return 0;
}