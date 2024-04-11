//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
bool ejz[100001];
int main()
{
    string a,b;
    cin>>a>>b;
    int target=0,known=0,ques=0,reach;
    for(unsigned int i=0;i<a.length();i++) if(a[i]=='+') target++; else target--;
    for(unsigned int i=0;i<b.length();i++) if(b[i]=='?') ques++; else if(b[i]=='+') known++; else known--;
    reach=target-known+ques;
    if(reach%2!=0) printf("0.000000000000");
    else
    {
        reach/=2;
        //quesreach
        int total=0,obey=0;
        while(!ejz[ques+1])
        {
            ejz[1]=!ejz[1];
            for(int i=1;i<=ques;i++)
            {
                if(!ejz[i]) ejz[i+1]=!ejz[i+1]; else break;
            }
            total++;
            int z=0;
            for(int i=ques;i>=1;i--) z+=ejz[i];
            obey+=z==reach;
        }
        printf("%.12lf",(double)obey/total);
    }
    return 0;
}