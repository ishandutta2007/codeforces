#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
string s;
int k;
bool pp(string a,int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        if(a[i]!=a[l+r-i]) return 0;
    }
    return 1;
}
int main()
{
    cin>>s>>k;
    int ls=s.length();
    if(ls%k!=0)
    {
        cout<<"NO";
        return 0;
    }
    int el=ls/k;
    for(int i=0;i<k;i++)
    {
        if(!pp(s,i*el,i*el+el-1))
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}