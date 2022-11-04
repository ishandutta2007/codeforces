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
#define ll long long
int inf=0x3f3f3f3f;
using namespace std;
int n;
int a[2010],b[2010];
int aa=0,bb=0;
ll sum=0;
int cmp(int q,int w)
{
    return q<w;
}
int main()
{
    int c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c%2)
        {
            a[aa++]=c;
        }
        else
        {
            b[bb++]=c;
        }
    }
    sort(a,a+aa,cmp);
    sort(b,b+bb,cmp);
    int d=min(aa,bb);
    for(int i=0;i<aa-d-1;i++)
        sum+=a[i];
    for(int i=0;i<bb-d-1;i++)
        sum+=b[i];
    cout<<sum;
    return 0;
}