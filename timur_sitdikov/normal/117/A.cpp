#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   

    int v, v_st, s, f, t, m, n, i, vec, ans;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d", &s, &f, &t);
        if (s==f) {printf("%d\n", t); continue;}
        ans=t/(2*m-2)*(2*m-2); t%=(2*m-2);
        if (t<m-1)
        {
            if (t<s)
            {
                vec=1; v_st=s-1;
            }
            if (t>=s)
            {
                vec=0; v_st=m-1+m-s;
            }
        }
        else
        {
            t=2*m-2-t;
            if (t>=s-1)
            {
                vec=0; v_st=m-1+m-s;
            }
            if (t<s-1)
            {
                vec=1; v_st=2*m-2+s-1;
            }
        }
        if (!vec)
        {
            if (s>f) v=v_st+s-f;
            else v=v_st+s-1+f-1;
        }
        else
        {
            if (s<f) v=v_st+f-s;
            else v=v_st+m-s+m-f;
        }
        ans+=v;
        printf("%d\n", ans);
    }
}