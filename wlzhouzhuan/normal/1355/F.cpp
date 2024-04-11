// Author: wlzhouzhuan
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

const int N=1000005;

int vis[N],pr[N],len;
void xxs(int n){
    rep(i,2,n){
        if(!vis[i]){
            pr[++len]=i;
            for(int j=i+i;j<=n;j+=i)vis[j]=1;
        }
    }
}
void solve(){
    int D=1;
    for(int i=1,turn=1;turn<=22;turn++){
        ll qwq=1;
        int next_i=i;
        for(int j=i;;j++){
            if(1.*qwq*pr[j]>1e18){
                next_i=j;
                break;
            }
            qwq*=pr[j];
        }
        ll ask=qwq;
        printf("? %lld\n",ask),fflush(stdout);
        ll t;scanf("%lld",&t);
        for(int j=i;j<next_i;j++){
            if(t%pr[j]==0){
                ll _=1;while(1.*_*pr[j]<=1e9)_*=pr[j];
                turn++;
                if(turn>22)break;
                printf("? %lld\n",_),fflush(stdout);
                ll __;scanf("%lld",&__);
                int k=0;
                while(__%pr[j]==0)__/=pr[j],k++;
                D*=(k+1);
            }
        }
        i=next_i;
//        printf("now D=%d\n",D);
    }
    printf("! %lld\n",max(2*D,D+7)),fflush(stdout);
}

int main(){
    xxs(1e6);
    int T=read();
    while(T--)solve();
    return 0;
} 

/*
916420788

*/