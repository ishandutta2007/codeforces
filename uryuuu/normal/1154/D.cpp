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
#define ll long long
#define N 500005
#define mod 1000000007
ll inf=1e18;
using namespace std;
int c;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int bb=b,t=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            if(a>0)
            {
                if(bb<b)
                {
                    a--;
                    bb++;
                }
                else if(b==bb)
                {
                    bb--;
                }
                t++;
            }
            else
            {
                if(bb==0)
                {
                    cout<<t<<endl;
                    return 0;
                }
                else
                {
                    bb--;
                    t++;
                }
            }
        }
        else if(c==0)
        {
            if(bb>0)
            {
                bb--;
                t++;
            }
            else
            {
                if(a>0)
                {
                    a--;
                    t++;
                }
                else
                {
                    cout<<t<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<n<<endl;
    return 0;
}