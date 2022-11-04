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
int a[100005];
int main()
{
    int flag=0;
    int n,aa;
    cin>>n;
    int s=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        aa=a[i];
        if(aa)
            flag=1;
        aa%=2;
        s+=aa;
    }
    sort(a,a+n);
    int fla=0,ff=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<i)
        {
            cout<<"cslnb"<<endl;
            return 0;
        }
        if(a[i]>i)
            fla=1;
        if(i+2<n&&(a[i]==a[i+1]&&a[i]==a[i+2]))
        {
            cout<<"cslnb"<<endl;
            return 0;
        }
        if(i+2<n&&(a[i]+1==a[i+1]&&a[i+1]==a[i+2]))
        {
            cout<<"cslnb"<<endl;
            return 0;
        }
        if(i+1<n&&(a[i]==a[i+1]))
        {
            ff++;
        }
    }
    if(flag==0||fla==0||ff>1)
    {
        cout<<"cslnb"<<endl;
        return 0;
    }
    if((s-((n/2)%2))%2==0)
        cout<<"cslnb"<<endl;
    else
        cout<<"sjfnb"<<endl;
    return 0;
}