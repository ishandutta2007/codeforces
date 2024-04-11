#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN];
vector<int> v;
mt19937 wcy(time(NULL));
bool online(int x,int y,int z)
{
    if(a[y]==a[x]&&(a[z]!=a[x])) return false;
    if(a[z]==a[x]&&(a[y]!=a[x])) return false;
    return 1LL*(b[y]-b[x])*(a[z]-a[x])==1LL*(b[z]-b[x])*(a[y]-a[x]);
}
double get_dist(int x,int y)
{
    return sqrt(1.0*(a[y]-a[x])*(a[y]-a[x])+1.0*(b[y]-b[x])*(b[y]-b[x]));
}
bool cmp(int x,int y)
{
    if(a[x]==a[y]) return b[x]<b[y];
    return a[x]<a[y];
}
int main()
{
    int id=-1;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    while(true)
    {
        int x=wcy()%n+1,y=wcy()%n+1;
        while(x==y) {x=wcy()%n+1; y=wcy()%n+1;}
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(i==x||i==y) continue;
            if(online(x,y,i)) cnt++;
        }
        if(cnt>=n-3)
        {
            v.push_back(x); v.push_back(y);
            for(int i=1;i<=n;i++)
            {
                if(i==x||i==y) continue;
                if(online(x,y,i)) v.push_back(i); else id=i;
            }
            sort(v.begin(),v.end(),cmp);
            break;
        }
    }
    /*
    printf("id=%d\n",id);
    for(auto x:v) printf("%d ",x);
    puts("");
    */
    if(k==id)
    {
        double ans=min(get_dist(v[0],k),get_dist(v.back(),k));
        for(int i=0;i<(int)v.size()-1;i++) ans+=get_dist(v[i],v[i+1]);
        printf("%.10f\n",ans);
    }
    else
    {
        //one end+now
        double ans=min(get_dist(v[0],id),get_dist(v.back(),id));
        for(int i=0;i<(int)v.size()-1;i++) ans+=get_dist(v[i],v[i+1]);
        ans+=get_dist(k,id);
        //repeat one end
        double res=0.0,sum=0.0,left=0.0;
        bool f=true;
        int pos=-1;
        for(int i=0;i<(int)v.size()-1;i++) 
        {
            sum+=get_dist(v[i],v[i+1]);
            if(v[i]==k) {pos=i; f=false;}
            if(f) left+=get_dist(v[i],v[i+1]);
        }
        if(pos==-1) pos=(int)v.size()-1;
        res=sum+min(left,sum-left);
        double mini=INF;
        for(int i=0;i<(int)v.size()-1;i++)
            mini=min(mini,get_dist(v[i],id)+get_dist(v[i+1],id)-get_dist(v[i],v[i+1]));
        res+=mini;
        ans=min(ans,res);
        ans=min(ans,sum+left+get_dist(id,v.back()));
        ans=min(ans,sum+sum-left+get_dist(id,v[0]));
        //sample case
        //printf("pos=%d\n",pos);
        if(pos!=0)
        {
            res=sum+get_dist(v.back(),id)-get_dist(v[pos-1],v[pos]);
            res+=min(get_dist(v[0],id),get_dist(v[pos-1],id));
            ans=min(res,ans);
        }
        if(pos!=(int)v.size()-1)
        {
            res=sum+get_dist(v[0],id)-get_dist(v[pos],v[pos+1]);
            res+=min(get_dist(v.back(),id),get_dist(v[pos+1],id));
            ans=min(res,ans);
        }
        printf("%.10f\n",ans);
    }
    return 0;
}