#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char a[3005];
int main()
{
    scanf("%s",a);
    int i;
    int n=strlen(a);
    int cnt=0;
    char l='0';
    for (i=0;i<n;i++)
    {
        if ((a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
        {
            cnt=0;
            l='0';
        }
        else
        {
            cnt++;
            if (l=='0') l=a[i];
            if (l!=a[i]) l='1';
            if ((cnt>=3)&&(l=='1'))
            {
                printf(" ");
                cnt=1;
                l=a[i];
            }
        }
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}