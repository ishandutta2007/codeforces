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
const ll Mod=998244353;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[2050];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='R')
                a[i]=0;
            else if(s[i]=='G')
                a[i]=1;
            else
                a[i]=2;
        }
        int zx=3000;
        for(int i=0;i+k-1<len;i++)
        {
            for(int f=0;f<3;f++)
            {
                int ff=f,sum=0;
                for(int j=0;j<k;j++,ff++)
                {
                    if(a[i+j]!=ff%3)
                        sum++;
                }
                zx=min(sum,zx);
                if(zx==0)
                    break;
            }
            if(zx==0)
                break;
        }
//        for(int i=0;i<len;i++)
//            cout<<a[i]<<' ';
//        cout<<endl;
//        cout<<len<<endl;
        cout<<zx<<endl;
    }
    return 0;
}