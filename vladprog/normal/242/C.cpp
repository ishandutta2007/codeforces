#include<bits/stdc++.h>

#define point pair<int,int>
#define x first
#define y second
#define el pair<point,int>
#define p first
#define d second

using namespace std;

int main()
{
    int x0,y0,x1,y1,n;
    scanf("%i%i%i%i%i",&x0,&y0,&x1,&y1,&n);
    set< point > s;
    for(int i=1;i<=n;i++)
    {
        int r,a,b;
        scanf("%i%i%i",&r,&a,&b);
        for(int c=a;c<=b;c++)
            s.insert(point(r,c));
    }
    s.erase(point(x0,y0));
    queue< el > q;
    q.push(el(point(x0,y0),0));
    while(!q.empty())
    {
        el te=q.front();
        q.pop();
        point tp=te.p;
        int td=te.d;
        for(int tx=tp.x-1;tx<=tp.x+1;tx++)
            for(int ty=tp.y-1;ty<=tp.y+1;ty++)
            {
                if(tx==tp.x&&ty==tp.y)continue;
                if(tx==x1&&ty==y1)
                    return printf("%i\n",td+1), 0;
                set< point >::iterator ti=s.find(point(tx,ty));
                if(ti==s.end())continue;
                s.erase(ti);
                q.push(el(point(tx,ty),td+1));
            }
    }
    printf("-1\n");
}