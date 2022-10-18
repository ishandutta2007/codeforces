#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d%*c",&n);
    int k=0,p=0;
    string s;
    for(int i=1;i<=n;i++)
    {
        char c;
        scanf("%c",&c);
        if(c=='B')
            p++;
        else
            if(p!=0)
            {
                k++;
                char cc[5];
                sprintf(cc,"%d ",p);
                //printf("%d ",p);
                s+=cc;
                p=0;
            }
    }
    if(p!=0)
    {
        k++;
        char cc[5];
        sprintf(cc,"%d ",p);
        //printf("%d ",p);
        s+=cc;
    }
    printf("%d\n%s",k,&s[0]);
}