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

void solve(){
    n=read(),m=read();
    vector<int> may;
    auto check=[&](int t){
        if(m%t==0)
            may.pb(t);
    };
    n--,m--;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            check(i);
            if(n/i!=i)check(n/i);
        }
    }    
    n++,m++;
    m-=2;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            check(i);
            if(n/i!=i)check(n/i);
        }
    } 
    m+=2;
    n-=2;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            check(i);
            if(n/i!=i)check(n/i);
        }
    } 
    n+=2;
    if(n%2==1&&m%2==0){
        may.pb(2);
    }
    if(n%2==0&&m%2==1){
        may.pb(2);
    }
    may.pb(1);
    sort(may.begin(),may.end());
    may.erase(unique(may.begin(),may.end()),may.end());
    printf("%d ",SZ(may));
    for(auto it:may)printf("%d ",it);
    puts("");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}