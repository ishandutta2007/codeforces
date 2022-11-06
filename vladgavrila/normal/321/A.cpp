#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int n, m, x, y, a, b, ok1, ok2, cx, cy, px, py;
string s;

int main()
{
  //  freopen("a.in", "r", stdin);
  //  freopen("a.out", "w", stdout);

    cin>>a>>b;
    cin>>s;

    if(a==0 && b==0)
    {
        printf("Yes\n");
        return 0;
    }

    n=s.size();
    for(int i=0; i<n; ++i)
    {
        if(s[i]=='U')
            ++y;
        if(s[i]=='D')
            --y;
        if(s[i]=='R')
            ++x;
        if(s[i]=='L')
            --x;
    }

    for(int i=0; i<n; ++i)
    {
        if(s[i]=='U')
            ++cy;
        if(s[i]=='D')
            --cy;
        if(s[i]=='R')
            ++cx;
        if(s[i]=='L')
            --cx;

        ok1=ok2=0;
        if(x==0)
        {
            if(cx==a)
                ok1=1;
            else
                continue;
        }
        else
        {
            if((a-cx)%x!=0)
                continue;
            px=(a-cx)/x;
        }

        if(y==0)
        {
            if(cy==b)
                ok2=1;
            else
                continue;
        }
        else
        {
            if((b-cy)%y!=0)
                continue;
            py=(b-cy)/y;
        }

        if(px>=0 && py>=0 && (ok1==1 || ok2==1 || px==py))
        {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}