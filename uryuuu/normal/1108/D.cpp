//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1000005;

int father[30010];
int size[30010];

int getf(int x)
{
    if(x==father[x])
        return x;
    return father[x]=getf(father[x]);
}
void jihe(int x,int y)
{
    x=getf(x);
    y=getf(y);
    father[y]=father[x];
}

//struct node
//{
//    int l,r
//}a[10];
int a[200005];
string s;
int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
            a[i]=0;
        else if(s[i]=='G')
            a[i]=1;
        else
            a[i]=2;
    }
    int s=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            a[i]=(a[i-1]+1)%3;
            if(a[i]==a[i+1])
                a[i]=3-a[i-1]-a[i+1];
            s++;
        }
    }
    
    int dd;
    cout<<s<<endl;
    for(int i=0;i<n;i++)
    {
        dd=a[i];
        if(dd==0)
            cout<<'R';
        else if(dd==1)
            cout<<'G';
        else
            cout<<'B';
    }
    cout<<endl;
    return 0;
}