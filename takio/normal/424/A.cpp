#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n,i,sum;
char s[1000];
int main(){
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        sum=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='x')sum++;
        }
        if(sum==n/2)
        {
            printf("0\n%s\n",s);
            continue;
        }
        printf("%d\n",(int)abs(n/2-sum));
        if(sum>n/2)
        {

            for(i=0;i<n;i++)
                if(s[i]=='x'&&sum>n/2)
                {printf("X");sum--;}
                else if(s[i]=='X')printf("X");
                else printf("x");
        }
        else if(sum<n/2)
        {

            for(i=0;i<n;i++)
                if(s[i]=='X'&&sum<n/2)
                {printf("x");sum++;}
                else if(s[i]=='x')printf("x");
                else printf("X");
        }
        printf("\n");
    }
}