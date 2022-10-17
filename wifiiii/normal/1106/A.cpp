#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

char g[505][505];
int n;
int check(int a,int b)
{
    if(a-1<=0||b-1<=0||a+1>n||b+1>n) return 0;
    if(g[a][b]=='X'&&g[a-1][b-1]=='X'&&g[a-1][b+1]=='X'&&g[a+1][b-1]=='X'&&g[a+1][b+1]=='X') return 1;
    return 0;
}
int main()
{
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        cin>>g[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(check(i,j)) cnt++;
    cout << cnt << endl;
}