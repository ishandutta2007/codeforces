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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;




string s;
int a[1050],b[1050];

int main()
{
    sync;
    cin>>s;
    int n=s.length();
    int L=999999,R=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            a[i+1]=1;
            L=min(L,i+1);
        }
        else
        {
            a[i+1]=-1;
            R=max(R,i+1);
        }
    }
    if(L==999999||R==-1)
    {
        cout<<0<<endl;
        return 0;
    }
    if(L>R)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    int cnt=0;
    int posl,posr;
    int fl,fr;
    while(L<R)
    {
        fl=0;
        fr=0;
        while(L<=R)
        {
            if(a[L]==1)
            {
                posl=L;
                L++;
                fl=1;
                break;
            }
            L++;
        }
        if(fl==0)
            break;
        while(R>=L)
        {
            if(a[R]==-1)
            {
                posr=R;
                R--;
                fr=1;
                break;
            }
            R--;
        }
        if(fr==0)
            break;
        b[cnt++]=posl;
        b[cnt++]=posr;
    }
    cout<<cnt<<endl;
    sort(b,b+cnt);
    for(int i=0;i<cnt;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}