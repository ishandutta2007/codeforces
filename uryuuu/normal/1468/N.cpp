#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a1, a2, a3, a4, a5;
        int c1, c2, c3;
        scanf("%d %d %d", &c1, &c2, &c3);
        scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
        if(a1<=c1)
        {
            c1-=a1;
        }
        else
        {
            puts("NO");
            continue;
        }
        if(a2<=c2)
        {
            c2-=a2;
        }
        else
        {
            puts("NO");
            continue;
        }
        if(a3<=c3)
        {
            c3-=a3;
        }
        else
        {
            puts("NO");
            continue;
        }
        if(a4>c1)
        {
            if(a4-c1<=c3)
            {
                c3-=(a4-c1);
            }
            else
            {
                puts("NO");
                continue;
            }
        }
        if(a5>c2)
        {
            if(a5-c2<=c3)
            {
                c3-=(a5-c2);
            }
            else
            {
                puts("NO");
                continue;
            }
        }
        puts("YES");
    }
}