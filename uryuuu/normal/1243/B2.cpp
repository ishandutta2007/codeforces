#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
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
const int maxn=500005;
int a[30];
struct node
{
    int l,r;
}b[400];
int main()
{
    sync;
    int T;
    cin>>T;
    string s;
    string t;
    while(T--)
    {
        mm(a);
        int n;
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            a[int(s[i]-'a')]++;
        }
        cin>>t;
        for(int i=0;i<n;i++)
        {
            a[int(t[i]-'a')]++;
        }
        
        int f=0;
        for(int i=0;i<28;i++)
        {
            if(a[i]%2)
            {
                cout<<"No"<<endl;
                f=1;
                break;
            }
        }
       if(f==1)
           continue;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=t[i])
            {
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]!=t[j])
                    {
                        if(s[j]==s[i])
                        {
                            b[cnt].l=j;
                            b[cnt++].r=i;
                            swap(t[i],s[j]);
                            break;
                        }
                        if(t[j]==s[i])
                        {
                            b[cnt].l=j;
                            b[cnt++].r=j;
                            swap(t[j],s[j]);
                            b[cnt].l=j;
                            b[cnt++].r=i;
                            swap(t[i],s[j]);
                            break;
                        }
                    }
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<b[i].l+1<<' '<<b[i].r+1<<endl;
        }
    }
    return 0;
}