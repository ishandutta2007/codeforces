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
const int maxn=100005;
const ll Mod=1000000007;

string s;
int main()
{
    sync;
    int t;
    cin>>t;
    ll sum=0;
    while(t--)
    {
        sum=0;
        cin>>s;
        int n=s.length();
        int f=0;
        int id;
        int dd=0;
        for(int i=0;i<n;i++)
        {
            id=int(s[i]-'0');
            if(id==0)
                f=1;
            if(id%2==0)
                dd++;
//            cout<<sum<<' '<<id<<' ';
            sum=(sum+id)%3;
        }
//        cout<<sum<<' '<<f<<' ';
        if(sum==0&&f==1&&dd>=2)
            cout<<"red"<<endl;
        else
            cout<<"cyan"<<endl;
    }
    
    return 0;
}