// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

const int N=45;
const int inf=1e9;

int a[N],vis[N];
int n,x,y;

int sol(vector<int>a){
//    for(auto v:a)printf("%d ",v);puts("");
    vector<vector<int>>dp(SZ(a),vector<int>(2));
    dp[0][0]=0,dp[0][1]=-inf;
    rep(i,1,SZ(a)-1){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    }    
    int res=max(dp[SZ(a)-1][0],dp[SZ(a)-1][1]);
    dp[0][0]=-inf,dp[0][1]=a[0];
    rep(i,1,SZ(a)-1){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=dp[i-1][0]+a[i];
    } 
    ckmax(res,dp[SZ(a)-1][0]);
    return res;
}

int main(){
    cin>>n>>x>>y;
    for(int i=0;i<x+y;i++)a[i]=n/(x+y)+(n%(x+y)>i); 
    int ans=0;   
    for(int i=0;i<x+y;i++){
        if(!vis[i]){
            int j=i;
            vector<int>zz;
            while(!vis[j]){
                vis[j]=1;
                zz.pb(a[j]);
                j=(j+x)%(x+y);
            }
            ans+=sol(zz);
        }
    }
    printf("%d\n",ans);
    return 0;
}