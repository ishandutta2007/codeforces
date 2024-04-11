#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
string strs[100];
bool chk(char a,char b,char c,char d,char s)
{
    return a==s||b==s||c==s||d==s;
}
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>strs[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int ff=chk(strs[i][j],strs[i][j+1],strs[i+1][j],strs[i+1][j+1],'f'),
            aa=chk(strs[i][j],strs[i][j+1],strs[i+1][j],strs[i+1][j+1],'a'),
            cc=chk(strs[i][j],strs[i][j+1],strs[i+1][j],strs[i+1][j+1],'c'),
            ee=chk(strs[i][j],strs[i][j+1],strs[i+1][j],strs[i+1][j+1],'e');
            if(ff&&aa&&cc&&ee) ++ans;
        }
    }
    cout<<ans;
}