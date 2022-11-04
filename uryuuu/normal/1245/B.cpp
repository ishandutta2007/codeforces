#include<iostream>
#include<stdio.h>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int N=100005;
const ll Mod=1000000007;

string ss;
int b[200];
int r,p,s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mm(b);
        int n;
        r=0;
        p=0;
        s=0;
        cin>>n;
        cin>>r>>p>>s;
        cin>>ss;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(ss[i]=='P'&&s>0)
            {
                s--;
                sum++;
                b[i]=3;
            }
            else if(ss[i]=='R'&&p>0)
            {
                p--;
                sum++;
                b[i]=2;
            }
            else if(ss[i]=='S'&&r>0)
            {
                r--;
                sum++;
                b[i]=1;
            }
        }
        if(sum>=(n+1)/2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]==0)
            {
                if(r>0)
                {
                    r--;
                    cout<<"R";
                }
                else if(p>0)
                {
                    p--;
                    cout<<"P";
                }
                else if(s>0)
                {
                    s--;
                    cout<<"S";
                }
            }
            else
            {
                if(b[i]==1)
                    cout<<"R";
                else if(b[i]==2)
                    cout<<"P";
                else
                    cout<<"S";
            }
        }
        cout<<endl;
    }
    return 0;
}