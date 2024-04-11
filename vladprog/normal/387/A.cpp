#include<bits/stdc++.h>

using namespace std;

int main()
{
    int h,m;
    scanf("%d:%d",&h,&m);
    int s=h*60+m;
    scanf("%d:%d",&h,&m);
    int t=h*60+m;
    int ans=(s+24*60-t)%(24*60);
    h=ans/60;
    m=ans%60;
    printf("%02d:%02d",h,m);
}