#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

const int maxi=20;
char s[20];
int h[10],k,i,head,j,l;

int main()
{
    scanf("%s %d",&s,&k);
    for(i=0;i<10;i++) h[i]=-1;
    for(i=0;i<strlen(s);i++) if (h[s[i]-'0']==-1) h[s[i]-'0']=i;
    for(l=0;l<strlen(s);l++)
    {
        for(i=0;i<10;i++) h[i]=-1;
        for(i=l;i<strlen(s);i++) if (h[s[i]-'0']==-1) h[s[i]-'0']=i;
        for(i=9;i>=0;i--) if ((h[i]!=-1)&&(h[i]-l<=k))
        {
            for(j=h[i];j>l;j--) s[j]=s[j-1];
            s[l]='0'+i;
            k-=(h[i]-l);
            head++;
            break;
        }
    }
    puts(s);
}