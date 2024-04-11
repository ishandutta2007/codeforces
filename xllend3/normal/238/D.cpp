/*
Date: 2014/10/26 18:50:19 Sunday
Author: xllend3
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<complex>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=2111111,M=111111;
int m,n,t,C,l[N],r[N],ini[N],num[N][10];
char s[N];
void del(int x){r[l[x]]=r[x];l[r[x]]=l[x];}
vector<int>vec[N];
int find(int x,int p){
    int l=0,r=SZ(vec[x])-1;
    while(l<r){
        int mid=l+r>>1;
        if(vec[x][mid]<p)l=mid+1;else r=mid;
    }return vec[x][l];
}
int calc(int l,int r){
    //printf("%d %d %d\n",find(ini[l],vec[l][0]),find(r+1,vec[l][0]),vec[l][0]);
    return min(find(ini[l],vec[l][0]),find(r+1,vec[l][0]));
}
int main()
{
    scanf("%d%d",&n,&C);scanf("%s",s+1);
    rep(i,0,n+1)l[i]=i-1,r[i]=i+1;
    int pt=1,dir=1,lst=0,time=0;
    rep(i,1,n)ini[i]=-1;
    while(1){
        time++;rep(i,0,9)num[time][i]=num[time-1][i];
        if(ini[pt]==-1)ini[pt]=l[pt];vec[pt].pb(time);
        //printf("%d %d %d %d\n",time,pt,dir,lst);
        if(pt==0||pt==n+1){pt=r[0],lst=0,dir=1;continue;}
        if(s[pt]>='0'&&s[pt]<='9'){
            num[time][s[pt]-'0']++;
            s[pt]--;if(s[pt]=='0'-1)del(pt);else lst=pt;
            if(dir)pt=r[pt];else pt=l[pt];
        }else{
            if(s[pt]=='<')dir=0;if(s[pt]=='>')dir=1;
            int tmp=lst;lst=pt;if(dir)pt=r[pt];else pt=l[pt];
            if(s[pt]=='<'||s[pt]=='>'||pt==0||pt==n+1)del(lst),lst=tmp;
        }
        if(r[0]==n+1||l[n+1]==0)break;
    }vec[pt].pb(++time);rep(i,0,n+1)vec[i].pb(inf);
    //rep(i,0,n+1){rep(j,0,SZ(vec[i])-1)printf("%d ",vec[i][j]);puts("");}
    rep(_,1,C){
        int x,y;scanf("%d%d",&x,&y);int tmp=calc(x,y)-1;
        //printf("%d %d:",x,y);
        rep(i,0,8)printf("%d ",num[tmp][i]-num[vec[x][0]-1][i]);
        printf("%d\n",num[tmp][9]-num[vec[x][0]-1][9]);
    }
    return 0;
}