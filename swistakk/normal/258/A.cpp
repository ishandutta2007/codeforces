#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define uint long long int
#define N 1000005
using namespace std;
char tab[N];
int dlug;
void pisz(int k)
{
    for(int i=1; i<=dlug; i++)
    {
        if(i!=k)
        {
            cout<<tab[i];
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%s", tab+1);
    dlug=1;
    while(tab[dlug])
    {
        dlug++;
    }
    dlug--;
    for(int i=1; i<=dlug; i++)
    {
        if(tab[i]=='0')
        {
            pisz(i);
            return 0;
        }
    }
    pisz(dlug);
    return 0;
}