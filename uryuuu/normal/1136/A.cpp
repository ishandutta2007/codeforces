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
const int maxn=8010;
struct node
{
    int l,r;
}a[105];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    int k;
    cin>>k;
    int s=n;
    for(int i=0;i<n;i++)
    {
        if(k>a[i].r)
            s--;
        else
            break;
    }
    cout<<s<<endl;
    return 0;
}