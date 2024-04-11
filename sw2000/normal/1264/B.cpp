#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int a[4];

int main()
{
    int cnt=0;
    for(int i=0;i<4;i++)cin>>a[i];
    for(int i=0;i<4;i++)
    {
        if(a[i])
        {
            cnt++;
        }
    }
    if(cnt==1)
    {
        for(int i=0;i<4;i++)
        {
            if(a[i]==1)
            {
                puts("YES");
                printf("%d ",i);
            }
            if(a[i]>1)puts("NO");
        }
    }
    if(cnt==2)
    {
        for(int i=0;i<3;i++)
        {
            if(a[i]&&a[i+1])
            {
                if(abs(a[i]-a[i+1])>1)puts("NO");
                else
                {
                    puts("YES");
                    if(a[i]>a[i+1])printf("%d ",i);
                    for(int j=0;j<min(a[i],a[i+1]);j++)
                        printf("%d %d ",i+1,i);
                    if(a[i]<a[i+1])printf("%d ",i+1);
                }
                break;
            }
            if(i==2)puts("NO");
        }
    }
    if(cnt>=3)
    {
        if(a[1]<a[0]||a[2]<a[3])puts("NO");
        else
        {
            a[1]-=a[0];
            a[2]-=a[3];
            if(abs(a[1]-a[2])>1)puts("NO");
            else
            {
                puts("YES");
                if(a[1]>a[2])printf("1 ");
                for(int i=0;i<a[0];i++)printf("0 1 ");
                for(int i=0;i<min(a[1],a[2]);i++)printf("2 1 ");
                for(int i=0;i<a[3];i++)printf("2 3 ");
                if(a[1]<a[2])printf("2 ");
            }
        }
    }
    return 0;
}