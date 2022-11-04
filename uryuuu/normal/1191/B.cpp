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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
string a,b,c;
int pd(char a,char b,char c,char d)
{
    if(c!=d)
        return 0;
    if(a-b<3&&a-b>-3)
        return 1;
    return 0;
}
int dpd(int a,int b,int c)
{
    if((a-b==1&&a-c==-1)||(a-b==-1&&a-c==1))
        return 1;
    return 0;
}
int tpd(char a,char b,char c,char d,char e,char f)
{
    if(e!=d||e!=f||d!=f)
        return 0;
    if(a==b&&b==c)
        return 1;
    if(a==b||b==c||a==c)
        return 0;
    int aa=(int)a,bb=(int)b,cc=(int)c;
    if(dpd(aa,bb,cc)||dpd(bb,aa,cc)||dpd(cc,aa,bb))
    return 1;
    return 0;
}
int main()
{
    cin>>a>>b>>c;
    if(tpd(a[0],b[0],c[0],a[1],b[1],c[1]))
        cout<<0<<endl;
    else if(pd(a[0],b[0],a[1],b[1])||pd(a[0],c[0],a[1],c[1])||pd(c[0],b[0],c[1],b[1]))
        cout<<1<<endl;
    else
        cout<<2<<endl;
    return 0;
}