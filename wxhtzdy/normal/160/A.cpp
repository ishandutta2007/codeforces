#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[105],s=0,t=0;
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),s+=a[i];
    sort(a,a+n);
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        s-=a[i],t+=a[i],cnt++;
        if(t>s){
            printf("%i",cnt);
            return 0;
        }
    }
    return 0;
}