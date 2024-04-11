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
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 1000100
using namespace std;
string s1,s2;
int main()
{
    sync
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s1>>s2;
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
        int k=0,a2;
        int len2=s2.length();
        for(int i=0;i<len2;i++)
        {
            if(s2[i]=='1')
            {
                a2=i;
                break;
            }
        }
        int len1=s1.length();
        if(a2>len1-1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=a2;i<len1;i++)
        {
//            k++;
            if(s1[i]=='1')
                break;
            k++;
        }
        cout<<k<<endl;
    }
    return 0;
}