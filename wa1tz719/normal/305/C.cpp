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
#include<fstream>
#include<stdio.h>
#include<utility>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]); 
    }
    sort(a,a+n);
    a[n]=-1;
    for (i=0;i<n;i++)
    {
        int sum=0;
        int j;
        for (j=i;a[j]==a[i];j++)
        {
            sum++;
        }
        int k=j-sum/2;
        for (;k<j;k++)
        {
            a[k]=a[i]+1;
        }
        int temp=a[i];
        for (k=i;k<j-sum/2;k++)
        {
            a[k]=-1;
        }
        if (sum%2==1) a[j-sum/2-1]=temp;
        i=j-sum/2-1;
    }
    sort(a,a+n);
    int tot=a[n-1];
    for (i=n-2;i>=0;i--)
    {
        if (a[i]>=0) tot--;
    }
    printf("%d\n",tot);
    return 0;
}