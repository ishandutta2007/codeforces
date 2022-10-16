#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 1000
#define pb push_back
#define F first
#define S second
using namespace std;
int a[maxn+5],b[maxn+5],n;
char s[maxn+5];
int main()
{
    int i;
    scanf("%d",&n);
    scanf("%s",s+1);
    rep(i,1,n) a[i]=s[i]-'0';
    scanf("%s",s+1);
    rep(i,1,n) b[i]=s[i]-'0';
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int ptr1=1,ptr2=1;
    while(ptr2<=n)
    {
        if(a[ptr1]<=b[ptr2]) ptr1++,ptr2++;
        else ptr2++;
    }
    printf("%d\n",n-ptr1+1);
    ptr1=1;ptr2=1;
    while(ptr2<=n)
    {
        if(a[ptr1]<b[ptr2]) ptr1++,ptr2++;
        else ptr2++;
    }
    printf("%d\n",ptr1-1);
    return 0;
}