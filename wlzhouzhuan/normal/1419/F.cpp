#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=1005;
const int fuck_szh[4][4] = {
{0, 1, 2, 4},
{1, 0, 8, 16},
{2, 8, 0, 32},
{4, 16, 32, 0}
};
struct dot{
  int x,y;
}a[N];
int sz[N];
int tmpx[N],tmpy[N],l1,l2;
int n;

int f[N],name[N];
int fuck[N][N];
int find(int x){
  return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
  f[find(x)]=find(y);
}
bool check(int T){
  rep(i,1,n)f[i]=i,name[i]=0;
  rep(i,1,n){
    rep(j,i+1,n){
      if(a[i].x==a[j].x&&abs(tmpy[a[i].y]-tmpy[a[j].y])<=T){
        merge(i,j);
      }
      if(a[i].y==a[j].y&&abs(tmpx[a[i].x]-tmpx[a[j].x])<=T){
        merge(i,j);
      }
    }
  }
  //cerr<<"!\n";
  int block=0;
  rep(i,1,n)if(find(i)==i){
    name[i]=block;
    block++;
  }
  rep(i,1,n)name[i]=name[find(i)];
  if(block>4)return false;
  if(block==1)return true;
  if(block==2){
    rep(i,1,n){
      rep(j,i+1,n){
        if(find(i)!=find(j)){
          if(abs(tmpx[a[i].x]-tmpx[a[j].x])<=T&&abs(tmpy[a[i].y]-tmpy[a[j].y])<=T){
            return true;
          }
          if(a[i].x==a[j].x&&abs(tmpy[a[i].y]-tmpy[a[j].y])<=2*T){
            return true;
          }
          if(a[i].y==a[j].y&&abs(tmpx[a[i].x]-tmpx[a[j].x])<=2*T){
            return true;
          }
        }
      }
    }
    return false;
  }
  memset(fuck,0,sizeof(fuck));
  if(block==3){
    rep(i,1,n){
      rep(j,i+1,n){
        if(find(i)!=find(j)){
          if(abs(tmpx[a[i].x]-tmpx[a[j].x])<=T&&abs(tmpy[a[i].y]-tmpy[a[j].y])<=T){
            fuck[a[i].x][a[j].y]|=fuck_szh[name[i]][name[j]];
            fuck[a[j].x][a[i].y]|=fuck_szh[name[i]][name[j]];
          }
        }
      }
    }
    rep(i,1,n){
      rep(j,1,n){
        if(sz[fuck[i][j]]>=2){
          return true;
        }
      }
    }
    return false;
  }
  if(block==4){
    rep(i,1,n){
      rep(j,i+1,n){
        if(find(i)!=find(j)){
          if(abs(tmpx[a[i].x]-tmpx[a[j].x])<=T&&abs(tmpy[a[i].y]-tmpy[a[j].y])<=T){
            fuck[a[i].x][a[j].y]|=fuck_szh[name[i]][name[j]];
            fuck[a[j].x][a[i].y]|=fuck_szh[name[i]][name[j]];
          }
        }
      }
    }
    rep(i,1,n){
      rep(j,1,n){
        if(__builtin_popcount(fuck[i][j])>=4){
          return true;
        }
      }
    }
    return false;
  }
  return false;
}
int main(){
  sz[0]=0;
  for(int i=1;i<=555;i++)sz[i]=sz[i>>1]+(i&1);
  n=read();
  rep(i,1,n){
    a[i].x=read(),a[i].y=read();
    tmpx[++l1]=a[i].x,tmpy[++l2]=a[i].y;
  } 
  sort(tmpx+1,tmpx+l1+1),l1=unique(tmpx+1,tmpx+l1+1)-(tmpx+1);
  sort(tmpy+1,tmpy+l2+1),l2=unique(tmpy+1,tmpy+l2+1)-(tmpy+1);
  rep(i,1,n){
    a[i].x=lower_bound(tmpx+1,tmpx+l1+1,a[i].x)-tmpx;
    a[i].y=lower_bound(tmpy+1,tmpy+l2+1,a[i].y)-tmpy;
  }
  ll l=0,r=2e9+1;
  while(l<r){
    ll mid=l+r>>1;
    if(check(mid))r=mid;
    else l=mid+1;
  }
  printf("%d\n",l==2e9+1?-1:l);
  return 0;
}