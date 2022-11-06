#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

int main()
{
    map <string, int> mp;
    int i, j, n, numa, numz;
    char c[10], c1[51], c2[51], reals[51];
    string str;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", &c);
        if (c[6])
        {
            scanf("%s %s", &c1, &c2);
            for(j=0; c1[j]=='&'; j++);
            numa=j;
            for(j=strlen(c1)-1; c1[j]=='*'; j--);
            numz=strlen(c1)-1-j;
            for(j=numa; c1[j]!='*' && c1[j]; j++)
                reals[j-numa]=c1[j];
            reals[j-numa]=0;
            str=reals;
            if (!str.compare("errtype"))
            {
                str=c2;
                mp[c2]=-1;
                continue;
            }
            if (!str.compare("void"))
            {
                str=c2;
                mp[c2]=numz-numa;
                if (mp[c2]<0) mp[c2]=-1;
                continue;
            }
            if (mp.find(str)==mp.end() || mp[str]==-1)
            {
                str=c2;
                mp[c2]=-1;
                continue;
            }
            numz+=mp[str];
            str=c2;
            mp[str]=numz-numa;
            if (mp[c2]<0) mp[c2]=-1;
        }
        else
        {
            scanf("%s", &c1);
            for(j=0; c1[j]=='&'; j++);
            numa=j;
            for(j=strlen(c1)-1; c1[j]=='*'; j--);
            numz=strlen(c1)-1-j;
            for(j=numa; c1[j]!='*' && c1[j]; j++)
                reals[j-numa]=c1[j];
            reals[j-numa]=0;
            str=reals;
            if (!str.compare("errtype"))
            {printf("errtype\n"); continue;}
            if (!str.compare("void"))
            {
                numz-=numa;
                if (numz<0){printf("errtype\n"); continue;}
                    printf("void");
                for(j=0; j<numz; j++) putchar('*');
                putchar('\n');
                continue;
            }
            if (mp.find(str)==mp.end() || mp[str]==-1)
            {printf("errtype\n"); continue;}
            numz+=mp[str]-numa;
            if (numz<0){printf("errtype\n"); continue;}
            printf("void");
            for(j=0; j<numz; j++) putchar('*');
            putchar('\n');
        }
    }
}