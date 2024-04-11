#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 100000
#define pb push_back
using namespace std;
typedef long long ll;
int a[maxn+5];
bool mark;
int main()
{
    int i,n;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,3,n) if(a[i]<a[i-1]+a[i-2]) mark=1;
    printf("%s\n",mark==1?"YES":"NO");
    return 0;
}