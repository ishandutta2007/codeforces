#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int a[101];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        char c[101];
        scanf("%s",c);
        string s=c;
        a[s.length()]++;
    }
    char c[101];
    scanf("%s",c);
    string s=c;
    int l=s.length();
    int p1=0;
    for(int i=1;i<l;i++)
        p1+=a[i];
    int p2=p1+a[l]-1;
    printf("%d %d",p1+p1/k*5+1,p2+p2/k*5+1);
}