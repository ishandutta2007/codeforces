#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char c[n][m+1];
    for(int i=0;i<n;i++)
        scanf("%s",c[i]);
    {
        char c1[n][m];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                c1[i][j]=c[i][j];
        #define c c1
        int x=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<m;j++)
                if(c[i][j]=='*')
                    s++;
            if(r<s)
                r=s,x=i;
        }
        for(int j=0;j<m;j++)
            c[x][j]='.';
        int y=-1;r=-1;
        for(int j=0;j<m;j++)
        {
            int s=0;
            for(int i=0;i<n;i++)
                if(c[i][j]=='*')
                    s++;
            if(r<s)
                r=s,y=j;
        }
        for(int i=0;i<n;i++)
            c[i][y]='.';
        bool yes=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(c[i][j]=='*')
                    yes=false;
        if(yes)
            printf("YES\n%d %d\n",x+1,y+1),exit(0);
        #undef c
    }
    {
        char c1[m][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                c1[j][i]=c[i][j];
        swap(n,m);
        #define c c1
        int x=-1,r=-1;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<m;j++)
                if(c[i][j]=='*')
                    s++;
            if(r<s)
                r=s,x=i;
        }
        for(int j=0;j<m;j++)
            c[x][j]='.';
        int y=-1;r=-1;
        for(int j=0;j<m;j++)
        {
            int s=0;
            for(int i=0;i<n;i++)
                if(c[i][j]=='*')
                    s++;
            if(r<s)
                r=s,y=j;
        }
        for(int i=0;i<n;i++)
            c[i][y]='.';
        bool yes=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(c[i][j]=='*')
                    yes=false;
        if(yes)
            printf("YES\n%d %d\n",y+1,x+1),exit(0);
        #undef c
    }
    printf("NO\n");
}