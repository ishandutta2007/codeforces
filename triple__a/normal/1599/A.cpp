#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
string str;
P ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    cin>>str;
    int now=n-1,l=0,r=n-1;
    while(now>=0)
    {
        if(now==0) {ans[now]=P(a[l],str[now]=='L'?0:1); break;}
        if(str[now]!=str[now-1])
        {
            ans[now]=P(a[r],str[now]=='L'?0:1);
            now--; r--;
        }
        else
        {
            if(now==1||str[now]==str[now-2])
            {
                ans[now-1]=P(a[r],str[now]=='L'?0:1);
                ans[now]=P(a[r-1],str[now]=='L'?1:0);
                now-=2; r-=2;
            }
            else if((r-l+1)&1)
            {
                ans[now-1]=P(a[r],str[now]=='L'?0:1);
                ans[now]=P(a[l],str[now]=='L'?0:1);
                now-=2; r--; l++;
            }
            else
            {
                ans[now-1]=P(a[r],str[now]=='L'?0:1);
                ans[now]=P(a[l],str[now]=='L'?1:0);
                now-=2; r--; l++;
            }
        }
    }
    for(int i=0;i<n;i++) printf("%d %c\n",ans[i].F,ans[i].S?'R':'L');
    return 0;
}