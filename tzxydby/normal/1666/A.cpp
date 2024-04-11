// Author: wlzhouzhuan
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>>
using namespace std;
using namespace __gnu_pbds;

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

mt19937_64 rng(114514);

const int N=20005;

char a[N];
ull val[N];
ull hsh[N],prehsh[N];
int n;
int ans;

/*
L 0
R 1
U 2
D 3
*/
bitset<20005> vis[20005];
int cnt[N][4];

int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    for(int i=1;i<=n;i++){
        val[i]=rng(),prehsh[i]=prehsh[i-1]^val[i];
        memcpy(cnt[i],cnt[i-1],sizeof(cnt[i-1]));
        if(a[i]=='L')cnt[i][0]++;
        else if(a[i]=='R')cnt[i][1]++;
        else if(a[i]=='U')cnt[i][2]++;
        else cnt[i][3]++;
    }
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n;i++){
            ull cur;
            if(a[i]=='L')cur=val[i-1];
            else if(a[i]=='R')cur=val[i+1];
            else if(a[i]=='U')cur=i>len?val[i-len]:0;
            else cur=i+len<=n?val[i+len]:0;
            hsh[i]=hsh[i-1]^cur^val[i];
        }
        for(int i=1;i+len-1<=n;i++){
            if((hsh[i+len-1]^hsh[i-1])==0){
                if(!vis[i].test(i+len-1)){
                    // printf("type 1: When len=%d,i=%d\n",len,i);
                    vis[i].set(i+len-1),ans++;
                }
            }
            if(cnt[i+len-1][2]-cnt[i-1][2])continue;
            if(a[i]=='L'||a[i+len-1]=='R')continue;
            ull k2=(hsh[i+len-1]^hsh[i-1]);
            for(int j=i+len;j+len-1<=n;j+=len){
                k2^=hsh[j+len-1]^hsh[j-1];
                if(a[j]=='L'||a[j+len-1]=='R')break;
                if(k2==0){
                    if(!vis[i].test(j+len-1)){
                        // printf("type 2: When len=%d,i=%d,j=%d\n",len,i,j);
                        vis[i].set(j+len-1),ans++;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}