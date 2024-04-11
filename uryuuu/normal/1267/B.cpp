#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
char s[500005];
vector<pair<char,int>> v;
int main()
{
    scanf("%s", s+1);
    int n=strlen(s+1);
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=i; j<=n; j++)
        {
            if(j==n&&s[i]==s[j])
            {
                i=n;
            }
            if(s[j]!=s[i])
            {
                i=j-1;
                break;
            }
            cnt++;
        }
        v.push_back({s[i], cnt});
    }
    int len=v.size(), f=0, res=0;
    if(len%2==1)
    {
        int mid=len/2;
        if(v[mid].second<2)
        {
            f=1;
        }
        else
        {
            res=v[mid].second+1;
        }
        for(int i=1; i<=len/2; i++)
        {
            if(v[mid+i].first!=v[mid-i].first||v[mid+i].second+v[mid-i].second<3)
            {
                f=1;
                break;
            }
        }
    }
    else
    {
        f=1;
    }
    if(f)
    {
        puts("0");
    }
    else
    {
        printf("%d\n", res);
    }
}