#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<double,double> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

char s[maxn];
int n,k;
bool solve()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(i>k&&s[i-k]!='?')
        {
            if(s[i]!='?'&&s[i]!=s[i-k])return 0;
            s[i]=s[i-k];
        }
        if(s[i]=='0')cnt1++;
        else if(s[i]=='1')cnt2++;
        if(i>k)
        {
            if(s[i-k]=='0')cnt1--;
            else if(s[i-k]=='1')cnt2--;
        }
        if(cnt1>k/2||cnt2>k/2)return 0;
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