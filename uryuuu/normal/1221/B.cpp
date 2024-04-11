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
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
int a[105][105];

int d[8][2]={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};


int main()
{
    mm(a);
    sync;
    int n;
    cin>>n;
    int s=1;
    for(int i=1;i<=n;i++)
    {
        s=i%2;
        for(int j=1;j<=n;j++)
        {
            if(s==0)
                cout<<"B";
            else
                cout<<"W";
            s^=1;
        }
        cout<<endl;
    }
    return 0;
}