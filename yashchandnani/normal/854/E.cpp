#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
vector<int> t[MAXN];
int n,q;
int p[MAXN];
void update(int x,int v){
  for(;x<MAXN;x+=x&-x)t[x].push_back(v);
}

int query(int x,int R){
  int res=0;
  for(;x>0;x-=x&-x)res+=lower_bound(t[x].begin(),t[x].end(),R+1)-t[x].begin();
  return res;
}
ll c2(int x){
  return 1ll*x*(x-1)/2;
}
int main(){
  scanf("%d%d",&n,&q);
  for(int i=1;i<=n;i++){
    scanf("%d",p+i);
    update(p[i],i);
  }
  for(int i=1;i<=q;i++){
    int l,d,r,u;
    scanf("%d%d%d%d",&l,&d,&r,&u);
    int A=query(d-1,l-1);
    int B=query(d-1,r)-A;
    int C=query(d-1,n)-A-B;
    int D=query(u,l-1)-A;
    int E=query(u,r)-A-B-D;
    int F=query(u,n)-A-B-C-D-E;
    int G=query(n,l-1)-A-D;
    int H=query(n,r)-A-B-D-E-G;
    int I=n-A-B-C-D-E-F-G-H;
    ll res=1LL*E*(n-1)+1LL*A*(E+F+H+I)+1LL*C*(E+D+H+G)+1LL*G*(E+F+B+C)+1LL*I*(E+D+A+B)+1LL*B*(n-A-B-C)+1LL*D*(n-A-D-G)+1LL*F*(n-F-I-C)+1LL*H*(n-H-G-I);
    res/=2;
    printf("%lld\n",res);
  }
  return 0;
}