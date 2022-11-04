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
const int maxn=100005;
const ll Mod=1000000007;


int a[1005],b[1005];
string s;


int main()
{
    sync;
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            a[i+1]=1;
        else
            a[i+1]=-1;
    }
    int s=0,l,sum;
    int zd=0;
    int L=1,R=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<=n;k++)
                b[k]=a[k];
            swap(b[i],b[j]);
            l=0;
            s=0;
            int xx=0;
            for(int k=1;k<=n;k++)
            {
//                xx=min(0,max(xx,s));
                s+=b[k];
                if(s<xx)
                {
                    xx--;
                    l=k;
                    xx=s;
                }
            }
            for(int k=1;k<=l;k++)
            {
                b[n+k]=b[k];
            }
            s=0;
            sum=0;
            for(int k=l+1;k<=l+n;k++)
            {
                s+=b[k];
                if(s==0)
                    sum++;
                if(s<0)
                    break;
            }
            if(s==0&&zd<sum)
            {
                zd=sum;
                L=j;
                R=i;
            }
        }
    }
    cout<<zd<<endl;
    cout<<L<<' '<<R<<endl;
    
    return 0;
}
/*
500
)())))()((()))(((()()))())(()((()())((()))(()))())((((()(()())()())))())()()(()(((((())()))())))()()(((()()())))()()(()(()))()(()(()()(()()()()))())()((()(()())))(((())()))(((())))(((()(())(())))()())((((()))()))()((((())))()())((()()()())())()()()(((()(((()))())))())()((((()(())(()(()))))))((((()())(())()())))((((())()(()))))((()(()(()))))((((())(()))))((((())())))()(((()())))(()(((())(())()()))())(((()())))(()(()()))(()((()()()())))()((()(()())))()()(()((()(()()()()()))))((((())(()())))())((((
*/