#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    int c=0,k=0;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            if(a>0)a--;
            else if(b>0)b--,c++;
            else if(c>0)c--;
            else k++;
        }
        else
        {
            if(b>0)b--;
            else k+=2;
        }
    }
    printf("%d",k);
}