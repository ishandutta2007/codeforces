#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1.1e7+10;

ll ans[maxn];

bool solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<ans[k])return 0;
    if(n%2!=k%2)return 0;
    return 1;
}

int main()
{
    for(int i=1;i<maxn;i++)ans[i]=ans[i-1]+i*2-1;
    int _;cin>>_;
    while(_--)
    {
        if(solve())puts("YES");
        else puts("NO");
    }
	return 0;
}