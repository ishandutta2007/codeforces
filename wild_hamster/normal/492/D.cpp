#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,x,y,i,t,cntx,cnty;
vector <int> rez;
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    cntx = cnty = 0;
    while (cntx < x||cnty < y)
    {
        if ((long long)(cntx+1)*y > (long long)(cnty+1)*x)
        {
            cnty++;
            rez.push_back(2);
        }
        else
        if ((long long)(cntx+1)*y < (long long)(cnty+1)*x)
        {
            cntx++;
            rez.push_back(1);
        } else
        {
            cntx++;
            cnty++;
            rez.push_back(3);
            rez.push_back(3);
        }
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d",&t);
        t--;
        int tmp = rez[t%(x+y)];
        if (tmp == 1)
            printf("Vanya\n");
        else if (tmp == 2)
            printf("Vova\n");
        else
            printf("Both\n");
    }
    return 0;
}