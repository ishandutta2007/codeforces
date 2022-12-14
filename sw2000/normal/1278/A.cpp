#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;

bool can(string a,string b)
{
    int cnt[150]={0};
    for(auto i:a)
    {
        cnt[i]++;
    }
    for(auto i:b)
    {
        cnt[i]--;
        if(cnt[i]<0)return 0;
    }
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        string a,b;
        cin>>a>>b;
        int len=a.length();
        if(len>b.length())
        {
            puts("NO");
            continue;
        }
        for(int i=0;i+len<=b.length();i++)
        {
            if(can(a,b.substr(i,len)))
            {
                puts("YES");
                break;
            }
            else if(i+len==b.length())
            {
                puts("NO");
            }
        }
    }
    return 0;
}