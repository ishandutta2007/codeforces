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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400050;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


int t;
string s;
int v[30];
int a[30];
int b[30];

int main()
{
    sync;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        mm(v);
        mm(a);
        cin>>s;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int id=ch(s[i]);
            if(v[id]==0)
            {
                a[cnt++]=id;
            }
            v[id]++;
        }
        sort(a,a+cnt);
        int pos=0;
        for(int i=0;i<cnt;i+=2)
        {
            b[pos++]=a[i];
        }
        for(int i=1;i<cnt;i+=2)
        {
            b[pos++]=a[i];
        }
        int f=0;
        for(int i=1;i<cnt;i++)
        {
            if(abs(b[i]-b[i-1])==1)
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            if(cnt==4)
            {
                swap(b[0],b[1]);
                swap(b[2],b[3]);
                for(int i=0;i<cnt;i++)
                {
                    for(int j=0;j<v[b[i]];j++)
                        cout<<char('a'+b[i]-1);
                }
                cout<<endl;
            }
            else if(cnt==3)
            {
                swap(b[0],b[2]);
                swap(b[1],b[2]);
                f=0;
                for(int i=1;i<cnt;i++)
                {
                    if(abs(b[i]-b[i-1])==1)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)
                {
                    cout<<"No answer"<<endl;
                }
                else
                {
                    for(int i=0;i<cnt;i++)
                    {
                        for(int j=0;j<v[b[i]];j++)
                            cout<<char('a'+b[i]-1);
                    }
                    cout<<endl;
                }
            }
            else
                cout<<"No answer"<<endl;
        }
        else
        {
            for(int i=0;i<cnt;i++)
            {
                for(int j=0;j<v[b[i]];j++)
                    cout<<char('a'+b[i]-1);
            }
            cout<<endl;
        }
    }
    
    return 0;
}