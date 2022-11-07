#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int n, m;

int main()
{
   // freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    string c1, c2;

    cin>>c1;
    cin>>c2;
    for(int i=0; i<c1.size(); ++i)
    {
        if(c1[i]!=c2[i])
            printf("1");
        else
            printf("0");
    }
    printf("\n");

    return 0;
}