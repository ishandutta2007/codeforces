#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=3e5+10;
const int inf=1e9+10;


int n;
int a[N];



int smin[N],smax[N];

int g[N],f[N];
bool check(int len){
    int tmin=0,tmax=0;
    smin[0]=smax[0]=n+1;
    for(int i=n;i>=1;i--){
      while (tmin&&a[i]<=a[smin[tmin]]) tmin--;
      smin[++tmin]=i;      
      
      while (tmax&&a[i]>=a[smax[tmax]]) tmax--;
      smax[++tmax]=i;
      int L=1,R=tmin;
      while (L<=R){
        int mid=(L+R)/2;
        if (a[i]-a[smin[mid]]>len) L=mid+1;
        else R=mid-1;
      }
      g[i]=smin[R]-1;
      L=1,R=tmax;
      while (L<=R){
        int mid=(L+R)/2;
        if (a[smax[mid]]-a[i]>len) L=mid+1;
        else R=mid-1;
      }
      g[i]=min(g[i],smax[R]-1);
    }
    memset(f,0,sizeof(f));
    f[1]=1;
    f[3]=-1;
    for(int i=1;i<=n;i++){
      f[i]+=f[i-1];
      if (f[i]){
        f[i+1]++;
        f[g[i]+1]--;
      }
    }
    return f[n];
}
void prepare(){
  
  cin>>n>>a[1]>>a[2];
  n+=2;
  for(int i=3;i<=n;i++) cin>>a[i];
}
int main(){
  prepare();
  int L=abs(a[2]-a[1]),R=inf;
  while (L<=R){
    int mid=(L+R)/2;
    if (check(mid)) R=mid-1;
    else L=mid+1;
  }
  cout<<L;
}