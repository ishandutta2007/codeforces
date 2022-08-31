#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char buff[505];
int main()
{
    scanf("%s", buff+1);
    int dlug=1;
    while(buff[dlug])
    {
        dlug++;
    }
    dlug--;
    int akt=0;
    int mini=0, maxi=0;
    for(int i=1; i<=dlug; i++)
    {
        if(buff[i]=='+')
        {
            akt++;
            maxi=max(maxi, akt);
        }
        else
        {
            akt--;
            mini=min(mini, akt);
        }
    }
    cout<<maxi-mini<<endl;
    // system("pause");
    return 0;
}