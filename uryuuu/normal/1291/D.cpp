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
const int maxn=200005;
const ll Mod=1e9+7;


string s;
int a[30][maxn];

int main()
{
    sync;
    int t;
    cin>>s;
    int n=s.length();
    int id;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=26;j++)
        {
            a[j][i]=a[j][i-1];
        }
        id=int(s[i-1]-'a')+1;
        a[id][i]++;
    }
    cin>>t;
    int l,r;
    int cnt=0;
    while(t--)
    {
        cin>>l>>r;
        cnt=0;
        for(int i=1;i<=26;i++)
        {
            if(a[i][r]-a[i][l-1]>0)
            {
                cnt++;
            }
        }
//        cout<<cnt<<endl;
        if(r-l==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s[l-1]!=s[r-1])
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(cnt>=3)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
    return 0;
}