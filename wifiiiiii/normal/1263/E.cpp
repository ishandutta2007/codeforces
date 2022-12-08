#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int cur = 1;
const int maxn = 1e6+5;
char s[1000005],t[1000005];
int ans[maxn];
int mx[maxn<<1],mn[maxn<<1],lz[maxn<<1];
void update(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        lz[rt] += val,mx[rt] += val,mn[rt] += val;
        return;
    }
    if(lz[rt])
    {
        lz[rt<<1] += lz[rt], lz[rt<<1|1] += lz[rt];
        mx[rt<<1] += lz[rt], mx[rt<<1|1] += lz[rt];
        mn[rt<<1] += lz[rt], mn[rt<<1|1] += lz[rt];
        lz[rt] = 0;
    }
    int m = (l+r)/2;
    if(L<=m) update(L,R,val,l,m,rt<<1);
    if(m< R) update(L,R,val,m+1,r,rt<<1|1);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int m = n/2+2;
    int le=0,ri=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i] == 'L') cur = max(cur-1, 1);
        else if(s[i] == 'R') cur++;
        else
        {
            if(t[cur] == '(') update(cur,m,-1,1,m,1),le--;
            else if(t[cur] == ')') update(cur,m,1,1,m,1),ri--;
            t[cur] = s[i];
            if(s[i] == '(') update(cur,m,1,1,m,1),le++;
            else if(s[i] == ')') update(cur,m,-1,1,m,1),ri++;
        }
        if(mn[1] || le!=ri) ans[i] = -1;
        else ans[i] = mx[1];
    }
    ii printf("%d ",ans[i]);
}