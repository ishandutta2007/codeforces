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

string ss[100005];
int ansl[500005],ansr[500005],ans0;
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i=1;i<=n;++i) cin>>ss[i];
    for(int i=1;i<=n;++i)
    {
        string cur = ss[i];
        int cnt = 0, ok = 1;
        for(int j=0,l=cur.size();j<l;++j)
        {
            if(cur[j]=='(') cnt++;
            else cnt--;
            if(cnt<0) {ok=0;break;}
        }
        if(ok)
        {
            if(!cnt)
            {
                if(ans0) ans0--,ans++;
                else ans0++;
            }
            else if(ansr[cnt]) ansr[cnt]--,ans++;
            else ansl[cnt]++;
            continue;
        }
        cnt = 0, ok = 1;
        for(int j=cur.size()-1;j>=0;--j)
        {
            if(cur[j]==')') cnt++;
            else cnt--;
            if(cnt<0) {ok=0;break;}
        }
        if(ok)
        {
            if(!cnt)
            {
                if(ans0) ans0--,ans++;
                else ans0++;
            }
            else if(ansl[cnt]) ansl[cnt]--,ans++;
            else ansr[cnt]++;
        }
    }
    cout<<ans<<endl;
}