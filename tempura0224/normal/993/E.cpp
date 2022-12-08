#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; i++ )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;
typedef vector<complex<double>> poly;
const double pi=acos(-1);

poly dft(poly f,int n,int rev){
   if(n==1)return f;
   poly g[2];
   rep(i,2)g[i].resize(n/2);
   rep(i,n/2){
       g[0][i]=f[2*i];
       g[1][i]=f[2*i+1];
   }
   g[0]=dft(g[0],n/2,rev);
   g[1]=dft(g[1],n/2,rev);
   complex<double> zeta=complex<double>(cos(2*pi/n),sin(2*pi/n)*rev);
   complex<double> ret=1;
   rep(i,n/2){
       f[i]=g[0][i]+ret*g[1][i];
       ret*=zeta;
   }
   rep(i,n/2){
       f[i+n/2]=g[0][i]+ret*g[1][i];
       ret*=zeta;
   }
   return f;
}

poly fft(poly g,poly h){
   poly f;
   int m=(int)g.size()+h.size()+1;
   int sz=1;
   while(sz<m)sz*=2;
   f.resize(sz,0);
   g.resize(sz,0);
   h.resize(sz,0);
   g=dft(g,sz,1);
   h=dft(h,sz,1);
   rep(i,sz)f[i]=g[i]*h[i];
   f=dft(f,sz,-1);
   rep(i,sz)f[i]/=sz;
   return f;
}
int main(){
   ll n,k;
   cin>>n>>k;
   poly v;
   ll cnt=0;
   v.push_back(1);
   rep(i,n){
       int x;
       cin>>x;
       if(x<k){
           cnt++;
           v.push_back(1);
       }
       else {
           v[cnt]+=1;
       }
   }
   cnt++;
   poly w(cnt);
   rep(i,cnt)w[i]=v[cnt-1-i];
   poly z=fft(v,w);
   ll sum=n*(n+1)/2;
   rep(i,cnt){
       ll y=(ll)(z[cnt+i].real()+0.5);
       sum-=y;
   }
   cout<<sum<<" ";
   rep(i,min(cnt,n))cout<<(ll)(z[cnt+i].real()+0.5)<<" ";
   rep(i,n-cnt)cout<<"0 ";
   cout<<endl;
   return 0;
}