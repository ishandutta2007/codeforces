#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n,m,nq;
long long ans;

void update(long long x)
{if(x>=0)
 {	if(ans==-1 || x<ans)
 		ans=x;
 }
}

void exgcd(int A,int B,long long &x,long long &y,int k)
{long long t;
 if(B==0)
 {	x=1;
 	y=0;
 	return;
 }
 exgcd(B,A%B,x,y,k);
 t=y;
 y=x-(ll)A/B*y;
 x=t;
}

int gcd(int x,int y)
{return y==0?x:gcd(y,x%y);
}

void calc(int f1,int f2,int sx,int sy)
{int k,d,N,M;
 long long x1,y1,x,y;
 
 k=f2*sy-f1*sx;
 
 d=gcd(2*n,2*m);
 //cout<<k<<" "
 if((k>0 && k%d!=0) || (k<0 && (-k)%d!=0)) return;
 N=2*n/d;
 M=2*m/d;
 exgcd(N,M,x,y,k/d);
 
 x=x*(k/d);
 y=y*(k/d);
 //cout<<N<<" "<<M<<" "<<d<<" "<<x<<" "<<y<<" "<<f1<<" "<<f2<<" "<<k<<endl;
 
 x1=(x%M+M)%M;
 if(x1==0 && f1==-1) x1+=M;
 y1=y-(ll)N*((x1-x)/M);
 
 //cout<<x1<<" "<<y1<<" "<<n*x1+f1*sx<<endl;
 
 update(2*n*x1+f1*sx);
 y1=(y%N+N)%N;
 if(y1>0) y1-=N;
 if(y1==0 && f2==-1) y1-=N;
 x1=x-(ll)M*(y1-y)/N;
 
 //cout<<x1<<" "<<y1<<" "<<n*x1+f1*sx<<endl;
 
 update(2*n*x1+f1*sx);
}

int main()
{int i,j,q,sx,sy;
 
 scanf("%d%d%d",&n,&m,&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d%d",&sx,&sy);
 	ans=-1;
 	calc(-1,-1,sx,sy);
 	calc(-1,1,sx,sy);
 	calc(1,-1,sx,sy);
 	calc(1,1,sx,sy);
 	printf("%I64d\n",ans);
 }
 return 0;
}