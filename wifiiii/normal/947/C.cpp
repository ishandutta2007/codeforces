#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int trie[9100000][2],cnt[9100000],id[9100000],a[9100000];
inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int main()
{
    int n=read();
    int tot = 0;
    for(int i=1;i<=n;++i) a[i]=read();
    for(int i=1;i<=n;++i)
    {
        int tmp = read();
        int p = 0;
        for(int i=30;i>=0;--i)
        {
            int k=0;
            if((1<<i) & tmp) k=1;
            if(!trie[p][k]) trie[p][k]=++tot;
            p=trie[p][k];
            cnt[p]++;
        }
        id[p] = tmp;
    }
    vector<int> ans;
    for(int i=1;i<=n;++i)
    {
        int tmp = a[i];
        int p = 0;
        for(int i=30;i>=0;--i)
        {
            int k=0;
            if((1<<i) & tmp) k=1;
            if(cnt[trie[p][k]])
            {
                cnt[trie[p][k]]--;
                p = trie[p][k];
            }
            else
            {
                cnt[trie[p][1-k]]--;
                p = trie[p][1-k];
            }
        }
        ans.push_back(tmp ^ id[p]);
    }
    for(int i:ans) printf("%d ",i);
}