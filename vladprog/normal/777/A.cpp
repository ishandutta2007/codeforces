#include<bits/stdc++.h>

using namespace std;

const int ans[6][3]={{0,1,2},{1,0,2},{1,2,0},
                     {2,1,0},{2,0,1},{0,2,1}};

int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    printf("%d\n",ans[n%6][x]);
}