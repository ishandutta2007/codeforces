/*
By: zzq
P1
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <stack>
using namespace std;
int rt[101][101];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) rt[1][i]=rt[i][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++) rt[i][j]=rt[i-1][j]+rt[i][j-1];
    }
    cout<<rt[n][n]<<"\n";
    return 0;
}