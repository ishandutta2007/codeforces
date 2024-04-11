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

int f[22*360+5];
// ban1 , ban2 
bool ban1[22][360],ban2[22][360];
int id[22][360],tot;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y){
    f[find(x)]=find(y);
}

int n;

void solve(){
    memset(ban1,0,sizeof(ban1));
    memset(ban2,0,sizeof(ban2));
    n=read(),tot=0;
    for(int i=1;i<=21;i++){
        for(int j=0;j<360;j++){
            id[i][j]=++tot;
            f[tot]=tot;
        }
    }
    for(int i=1;i<=n;i++){
        char opt[3];
        scanf("%s",opt);
        if(opt[0]=='C'){
            int r=read(),k1=read(),k2=read();
            if(k1>k2){
                for(int i=k1;i<360;i++)
                    ban2[r][i]=1;
                for(int i=0;i<k2;i++)
                    ban2[r][i]=1;
            }else{
                for(int i=k1;i<k2;i++)
                    ban2[r][i]=1;
            }
        }else{
            int r1=read(),r2=read(),k1=read();
            k1=(k1+360-1)%360;
            for(int i=r1+1;i<=r2;i++)
                ban1[i][k1]=1;
        }
    }
    for(int i=1;i<=21;i++){
        for(int j=0;j<360;j++)
            if(!ban1[i][j])
                merge(id[i][j],id[i][(j+1)%360]);
        if(i<21)
            for(int j=0;j<360;j++)
                if(!ban2[i][j])
                    merge(id[i][j],id[i+1][j]);
    }
    int t=find(id[1][0]);
    for(int i=0;i<360;i++)
        if(find(id[21][i])==t){
            puts("YES");
            return ;
        }
    puts("NO");
}

int main(){
    int T=read();
    while(T--)solve();
    return 0;
}