#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

string S = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char s[105];
char g[105][105];
char ans[105][105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s+1);
            for(int j=1;j<=m;++j) g[i][j]=s[j];
        }
        int cnt=0;
        ii jj if(g[i][j]=='R') cnt++;
        int a=0,cnta=0,b=0,cntb=0;
        if(cnt % k == 0)
        {
            a=cnt/k;
            cnta=k;
        }
        else
        {
            a=cnt/k;b=cnt/k+1;
            cntb=cnt%k;cnta=k-cntb;
            assert(a*cnta+b*cntb == cnt && cnta+cntb == k && b-a==1);
        }
        int f=1;
        int tmp=0,cur=0;
        for(int i=1;i<=n;++i)
        {
            if(f)
            {
                for(int j=1;j<=m;++j)
                {
                    ans[i][j] = S[cur];
                    if(g[i][j] == 'R')
                    {
                        tmp++;
                        if(cnta && tmp == a)
                        {
                            tmp = 0;
                            cur++;
                            cnta--;
                        }
                        if(!cnta && tmp == b)
                        {
                            tmp = 0;
                            cur++;
                        }
                        cur = min(cur, k-1);
                    }
                }
            }
            else
            {
                for(int j=m;j>=1;--j)
                {
                    ans[i][j] = S[cur];
                    if(g[i][j] == 'R')
                    {
                        tmp++;
                        if(cnta && tmp == a)
                        {
                            tmp = 0;
                            cur++;
                            cnta--;
                        }
                        if(!cnta && tmp == b)
                        {
                            tmp = 0;
                            cur++;
                        }
                        cur = min(cur, k-1);
                    }
                }
            }
            f=1-f;
        }
        ii
        {
            jj printf("%c",ans[i][j]);
            puts("");
        }
    }
}