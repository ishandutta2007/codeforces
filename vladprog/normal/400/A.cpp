#include<bits/stdc++.h>

using namespace std;

const int A[6]={1,2,3,4,6,12},B[6]={12,6,4,3,2,1};

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        char c[13];
        scanf("%s",c);
        int k=0;
        for(int j=0;j<6;j++)
        {
            bool ok1=false;
            for(int l=0;l<B[j];l++)
            {
                bool ok2=true;
                for(int m=0;m<A[j];m++)
                    if(c[m*B[j]+l]=='O')
                        ok2=false;
                ok1|=ok2;
            }
            if(ok1)
                k++;
        }
        printf("%d",k);
        for(int j=0;j<6;j++)
        {
            bool ok1=false;
            for(int l=0;l<B[j];l++)
            {
                bool ok2=true;
                for(int m=0;m<A[j];m++)
                    if(c[m*B[j]+l]=='O')
                        ok2=false;
                ok1|=ok2;
            }
            if(ok1)
                printf(" %dx%d",A[j],B[j]);
        }
        printf("\n");
    }
}