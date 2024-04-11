#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int s=0,p=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>p)
        {
            //printf(">");
            if(s>0)
                printf("NO"),exit(0);
        }
        else if(a==p)
        {
            //printf("=");
            if(s>1)
                printf("NO"),exit(0);
            else
                s=1;
        }
        else if(a<p)
        {
            //printf("<");
            s=2;
        }
        p=a;
    }
    printf("YES");
}