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

const int maxn = 100005;

int bit[27][maxn];

int sum(int p,int x)
{
    int ret=0;
    for(;x;x-=x&-x) ret+=bit[p][x];
    return ret;
}
int n;
void add(int p,int x,int val)
{
    for(;x<=n;x+=x&-x) bit[p][x]+=val;
}

char s[200005];
inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int main()
{
    scanf("%s",s+1);
    n = strlen(s+1);
    for(int i=1;i<=n;++i) add(s[i]-'a',i,1);
    int q = read();
    while(q--)
    {
        int op = read();
        if(op==1)
        {
            int pos;
            char c;
            scanf("%d %c",&pos,&c);
            add(s[pos]-'a',pos,-1);
            add(c-'a',pos,1);
            s[pos]=c;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            int ans=0;
            for(int i=0;i<26;++i) {
                if(sum(i,r) - sum(i,l-1)) ans++;
            }
            printf("%d\n",ans);
        }
    }
}