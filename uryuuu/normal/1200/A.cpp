#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 300050
using namespace std;
int a[15];
int main()
{
    sync
    int n;
    char s;
    cin>>n;
    mm(a);
    for(int j=0;j<n;j++)
    {
        cin>>s;
        if(s=='L')
        {
            for(int i=0;i<10;i++)
                if(a[i]==0)
                {
                    a[i]=1;
                    break;
                }
        }
        if(s=='R')
        {
            for(int i=9;i>=0;i--)
                if(a[i]==0)
                {
                    a[i]=1;
                    break;
                }
        }
        if(s>='0'&&s<='9')
            a[s-'0']=0;
    }
    for(int i=0;i<10;i++)
        cout<<a[i];
    cout<<endl;
    return 0;
}