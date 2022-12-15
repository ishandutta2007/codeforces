#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <climits>
#include <set>
using namespace std;

vector<int> arr[3005]; 
int com[3005][3005];
bool has[3005][3005];
bool comm[3005];
int calcCom(int a, int b)
{
    if(com[a][b]!=-1)
        return com[a][b];
    memset(comm,0,sizeof(comm));
    for (int i = 0; i < arr[a].size(); ++i)
        comm[arr[a][i]]=true;
    int tot=0;
    for (int i = 0; i < arr[b].size(); ++i)
        if(comm[arr[b][i]])
            tot++;
        return com[a][b]=tot;
}
int main()
{
    int n,m;cin>>n>>m;
    memset(com,-1,sizeof(com));
    for (int i = 0; i < m; ++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a].push_back(b);
        has[a][b]=true;
    }
    long long sum=0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            for (int k = j+1; k < arr[i].size(); ++k)
            {
                sum+=calcCom(arr[i][j],arr[i][k]);
                if(has[arr[i][j]][i] && has[arr[i][k]][i] )
                    sum--;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}