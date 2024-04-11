
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;
int g[505][505], same[505];
int ans[505];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        same[i] = 1;
        for(int j=1;j<=m;++j)
        {
            cin>>g[i][j];
            if(g[i][j]!=g[i][1]) same[i]=0;
        }
    }
    int mk = -1;
    for(int i=1;i<=n;++i) if(!same[i]) {mk=i;break;}
    if(mk==-1)
    {
        int tmp = 0;
        for(int i=1;i<=n;++i) tmp ^= g[i][1];
        if(tmp==0)
        {
            cout << "NIE" << endl;
        }
        else
        {
            cout << "TAK" << endl;
            for(int i=1;i<=n;++i) cout<<1<<" ";
            cout<<endl;
        }
        return 0;
    }
    int tmp = 0;
    for(int i=1;i<=n;++i)
    {
        if(i==mk) continue;
        tmp ^= g[i][1];
    }
    for(int i=1;i<=m;++i)
    {
        if(tmp ^ g[mk][i])
        {
            cout << "TAK" << endl;
            for(int j=1;j<=n;++j)
            {
                if(j!=mk) cout<<1<<" ";
                else cout<<i<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    cout <<"wtf" <<endl;
}