#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c[100001];
    scanf("%s",c);
    string s=c;
    int n=s.length();
    int a[n];
    a[0]=0;
    for(int i=1;i<=n;i++)
        a[i]=a[i-1]+(s[i]==s[i-1]);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",a[r-1]-a[l-1]);
    }
}