// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<typename T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
    print(x),putchar(ch);
}

int n,m;

int ask(int x,int y){
    printf("SCAN %d %d\n",x,y),fflush(stdout);
    return read();
}

void solve(){
    scanf("%d%d",&n,&m);
    int a1=ask(1,1),a2=ask(n,1);
    int sumy=(a1+a2+4+2-2*n)/2,sumx=a1+4-sumy;
    int a3=ask(sumx/2,1),a4=ask(1,sumy/2);
    int difx=a3-sumy+2,dify=a4-sumx+2;
    // printf("sumx=%d,difx=%d,sumy=%d,dify=%d\n",sumx,difx,sumy,dify);
    int x1=(sumx+difx)/2,x2=abs(sumx-difx)/2;
    int y1=(sumy+dify)/2,y2=abs(sumy-dify)/2;
    printf("DIG %d %d\n",x1,y1),fflush(stdout);
    int x;scanf("%d",&x);
    if(x){
        printf("DIG %d %d\n",x2,y2),fflush(stdout);
        read();
    }else{
        printf("DIG %d %d\n",x1,y2),fflush(stdout);
        read();
        printf("DIG %d %d\n",x2,y1),fflush(stdout);
        read();
    }
}

int main(){
    // freopen("data.in","r",stdin);
    int T;
    for(scanf("%d",&T);T;T--){
        solve();
    }
    return 0;
}