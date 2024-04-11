#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int total=0;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        total+=a[i];
    }
    int j;
    int ma=0;
    for (i=0;i<n;i++)
    {
        int sum=0;
        for (j=i;j<n;j++)
        {
            if (a[j]==0) sum++; else sum--;
            ma=max(ma,total+sum);
        }
    }
    printf("%d\n",ma);
    //system("pause");
    return 0;
}