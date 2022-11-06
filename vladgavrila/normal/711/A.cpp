#include <stdio.h>
#include <iostream>

using namespace std;

#define maxn 100010

int n, seat;
string s[maxn];
int main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>s[i];
    for(int i=0; i<n; ++i)
        for(int j=0; j<5; j+=3)
            if((!seat) && s[i][j]=='O' && s[i][j+1]=='O')
            {
                seat=1;
                s[i][j]=s[i][j+1]='+';
            }
    if(!seat)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for(int i=0; i<n; ++i)
            cout<<s[i]<<"\n";
    }

    return 0;
}