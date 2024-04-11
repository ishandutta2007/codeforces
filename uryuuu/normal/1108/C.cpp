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
    int x=0,y=1,z=2;
    int s=9999999;
    int ss=0;
    int b[5];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
//            cout<<j<<endl;
//            cout<<j<<endl;
//            cout<<i<<' '<<j<<endl;
            ss=0;
            if(i==j)
            {
//                cout<<i<<' '<<j<<endl;
                continue;
            }
            b[0]=i;
            b[1]=j;
            b[2]=3-i-j;
            for(int k=0;k<n;k++)
            {
                if(a[k]!=b[k%3])
                    ss++;
            }
//            cout<<ss<<' '<<"DLJ"<<b[0]<<' '<<b[1]<<' '<<b[2]<<endl;
            if(ss<s)
            {
                s=ss;
                x=b[0];
                y=b[1];
                z=b[2];
            }
        }
    }
    b[0]=x;
    b[1]=y;
    b[2]=z;
    int dd;
    cout<<s<<endl;
//    cout<<x<<' '<<y<<' '<<z<<endl;
//    for(int i=0;i<n;i++)
//        cout<<a[i]<<' ';
    for(int i=0;i<n;i++)
    {
        dd=b[i%3];
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