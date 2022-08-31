#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#define N 100005
using namespace std;
char slo[N];
vector<int> lit[150];
int main()
{
    //ios_base::sync_with_stdio(0);
    scanf("%s", slo+1);
    int dlug=1;
    while(slo[dlug]!=0)
    {
        dlug++;
    }
    dlug--;
    int n=dlug;
    for(int i=1; i<=n; i++)
    {
        lit[int(slo[i])].push_back(i);
    }
    int last=0;
    for(int i=int('z'); i>=int('a'); i--)
    {
        for(int j=0; j<lit[i].size(); j++)
        {
            if(lit[i][j]>last)
            {
                cout<<char(i);
                last=lit[i][j];
            }
        }
    }
    cout<<endl;
    
    
    
    
    return 0;
}