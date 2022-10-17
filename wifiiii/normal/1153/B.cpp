
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
#include <unordered_map>
using namespace std;
typedef long long ll;

int a[105],b[105];
int g[105][105];
int main()
{
    memset(a,0x3f,sizeof(a));
    memset(b,0x3f,sizeof(b));
    int m,n,h;
    cin>>m>>n>>h;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>g[i][j];
            if(g[i][j])
            {
                g[i][j] = min(a[j], b[i]);
            }
        }
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}