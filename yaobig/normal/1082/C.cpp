#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vi s[maxn+5];
struct node
{
    int x,id;
    node(){}
    node(int a,int b):x(a),id(b){}
}cnt[maxn+5];
bool cmp(node a,node b) {return a.x>b.x;}
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m) s[i].pb(0);
    rep(i,1,n)
    {
        int x,y; scanf("%d%d",&x,&y);
        s[x].pb(y);
    }
    rep(i,1,m) sort(s[i].begin()+1,s[i].end(),greater<int>());
    rep(i,1,m)
    {
        int l=s[i].size();
        rep(j,1,l-1) s[i][j]+=s[i][j-1];
    }
    rep(i,1,m) cnt[i]=node(s[i].size()-1,i);
    sort(cnt+1,cnt+m+1,cmp);
    int ans=0,Ms=cnt[1].x;
    rep(i,1,Ms)
    {
        int tmp=0;
        rep(j,1,m)
        {
            if(cnt[j].x<i) break;
            if(s[cnt[j].id][i]>0) tmp+=s[cnt[j].id][i];
        }
        ans=max(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}