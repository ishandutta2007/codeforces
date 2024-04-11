#include<bits/stdc++.h>

using namespace std;

int main()
{
    int px,py;
    scanf("%d%d",&px,&py);
    if(px==0&&py==0)return printf("0"),0;
    int x=0,y=0,c=0,t=0;
    while(true)
    {
        t++;
        for(int i=0;i<t;i++)
            if(++x==px&&y==py)
                return printf("%d",c),0;
            //else printf("%d %d\n",x,y);
        c++;
        for(int i=0;i<t;i++)
            if(++y==py&&x==px)
                return printf("%d",c),0;
            //else printf("%d %d\n",x,y);
        t++;
        c++;
        for(int i=0;i<t;i++)
            if(--x==px&&y==py)
                return printf("%d",c),0;
            //else printf("%d %d\n",x,y);
        c++;
        for(int i=0;i<t;i++)
            if(--y==py&&x==px)
                return printf("%d",c),0;
            //else printf("%d %d\n",x,y);
        c++;
        //scanf("%*c");
    }
}