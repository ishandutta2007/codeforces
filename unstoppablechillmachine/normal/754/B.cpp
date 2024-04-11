#include <bits/stdc++.h>

using namespace std;

#define itn int
#define fro for
#define ld long double
#define ll long long
#define f first
#define sc second

struct kn
{
    int free,kol;
};

char ch;

int a[10][10];

int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);


    for (int i=1;i<=4;i++)
    for (int j=1;j<=4;j++)
    {
        cin>>ch;
        if (ch=='.') a[i][j]=1;
        if (ch=='x') a[i][j]=2;
    }

    for (int i=1;i<=4;i++)
    for (int j=1;j<=4;j++)
    {
        if (a[i][j]==1)
        {
            if (a[i+1][j]==2 && a[i-1][j]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i][j+1]==2 && a[i][j-1]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i+1][j+1]==2 && a[i-1][j-1]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i+1][j-1]==2 && a[i-1][j+1]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i+1][j]==2 && a[i+2][j]==2)
            {
                cout<<"YES";
                exit(0);
            }

            if (a[i-1][j]==2 && i-2>0 && a[i-2][j]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i][j+1]==2 && a[i][j+2]==2)
            {
                cout<<"YES";
                exit(0);
            }
            if (a[i][j-1]==2 && j-2>0 && a[i][j-2]==2)
            {
                cout<<"YES";
                exit(0);
            }

            if (a[i+1][j+1]==2 && a[i+2][j+2]==2)
            {
                cout<<"YES";
                exit(0);
            }

            if (a[i-1][j-1]==2 && i-2>0 && j-2>0 && a[i-2][j-2]==2)
            {
                cout<<"YES";
                exit(0);
            }

            if (a[i+1][j-1]==2 && j-2>0 && a[i+2][j-2]==2)
            {
                cout<<"YES";
                exit(0);
            }

            if (a[i-1][j+1]==2 && i-2>0 && a[i-2][j+2]==2)
            {
                cout<<"YES";
                exit(0);
            }

        }
    }

    cout<<"NO";
   return 0;
}