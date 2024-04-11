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
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
char a[200010];
char b[200010];
int main()
{
    int n;
    cin>>n;
    int t=0;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        for(;j<n;j++)
        {
            if(a[i]!=a[j])
            {
                b[t++]=a[i];
                b[t++]=a[j];
                break;
            }
        }
        if(j>=n)
            break;
        else
            i=j;
    }
    cout<<n-t<<endl;
    for(int i=0;i<t;i++)
        cout<<b[i];
    cout<<endl;
    return 0;
}