#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string.h>
using namespace std;
int m,n,sx,sy,ex,ey,x,y,a[100000],s,t,i,j,k;
string c;
void dfs()
{
if (k>=n||(x==ex&&y==ey)) return;
if (y>ey&&c[k]=='S') y--;
if (y<ey&&c[k]=='N') y++;
if (x>ex&&c[k]=='W') x--;
if (x<ex&&c[k]=='E') x++;
k++;dfs();
}
int main() {
cin>>n>>sx>>sy>>ex>>ey;
cin>>c;
x=sx;y=sy;
dfs();
if (x==ex&&y==ey) cout<<k; else cout<<-1;
//system("pause");
return 0;
}