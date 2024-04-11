#include <bits/stdc++.h>
using namespace std;
const int N=1010;

char s[N];

bool solve()
{
    int n;scanf("%d",&n);
    int cnt[150]={};
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
        {
            cnt[s[j]]++;
        }
    }
    for(int i='a';i<='z';i++)
    {
        if(cnt[i]%n)return 0;
    }
    return 1;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
    return 0;
}