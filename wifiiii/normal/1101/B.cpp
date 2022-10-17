#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int mod = 1e9+7;

int main()
{
    string s;
    cin>>s;

    int l1=-1,r1=-1;
    for(int i=0,l=s.size();i<l;++i)
    {
        if(s[i]=='[')
        {
            if(l1==-1) l1=i;
        }
        if(s[i]==']')
        {
            r1=i;
        }
    }
    if(l1==-1||r1==-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans = -1;
    int l11=-1,r11=-1;
    for(int i=l1,j=r1;i<=j;++i)
    {
        if(s[i]==':') {l11=i;break;}
    }
    for(int i=l1,j=r1;i<=j;--j)
    {
        if(s[j]==':') {r11=j;break;}
    }
    if(r11!=l11)
    {
        int cnt = 0;
        for(int i=l11,j=r11;i<=j;++i)
        {
            if(s[i]=='|') cnt++;
        }
        if(l11!=-1&&r11!=-1) ans=cnt+4;

    }
    cout<<ans<<endl;
}