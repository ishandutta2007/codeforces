#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 1000050
using namespace std;
int net[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string ans;
    int n,asz;
    cin>>n>>ans;
    for(int i=1;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        int sz=tmp.size();
        int p=0;
        net[0]=net[1]=0;
        for(int i=2;i<=sz;i++)
        {
            while(p&&tmp[i-1]!=tmp[p])
                p=net[p];
            if(tmp[i-1]==tmp[p])
                p++;
            net[i]=p;
        }
        p=0;
        asz=ans.size();
        for(int i=max(1,asz-sz+1);i<=asz;i++)
        {
            while(p&&ans[i-1]!=tmp[p])
                p=net[p];
            if(ans[i-1]==tmp[p])
                p++;
        }
        for(int i=p;i<sz;i++)
        {
            ans+=tmp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}