#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long
const int mod=1000000007;

struct matrix
{int val[3][3];
};
struct matrix g,e,w;

struct unit
{int s1,s2;
 matrix tag;
};
struct unit t[800010];

int n,nq,ans;
int a[400010],b[400010];

matrix operator *(matrix A,matrix B)
{matrix ret;
 int i,j,k;
  
 ret.val[1][1]=ret.val[1][2]=ret.val[2][1]=ret.val[2][2]=0;
 for(i=1;i<=2;i++)
 	for(j=1;j<=2;j++)
 		for(k=1;k<=2;k++)
 			ret.val[i][k]=(ret.val[i][k]+(ll)A.val[i][j]*B.val[j][k]%mod)%mod;		
 return ret;
}

matrix fpow(matrix A,int j)
{matrix ret=e;
 for(;j;A=A*A,j/=2)
 	if(j&1) ret=ret*A;
 return ret;
}

void build(int p,int l,int r)
{t[p].tag=e;
 if(l==r)
 {	t[p].s1=a[l];
 	t[p].s2=b[l];
 	return;
 }
 build(p*2,l,(l+r)/2);
 build(p*2+1,(l+r)/2+1,r);
 t[p].s1=(t[p*2].s1+t[p*2+1].s1)%mod;
 t[p].s2=(t[p*2].s2+t[p*2+1].s2)%mod;
}

void push_down(int p)
{int k1,k2,i;
 
 i=p*2;
 k1=t[i].s1;
 k2=t[i].s2;
 t[i].s1=((ll)k1*t[p].tag.val[1][1]%mod+(ll)k2*t[p].tag.val[2][1]%mod)%mod;
 t[i].s2=((ll)k1*t[p].tag.val[1][2]%mod+(ll)k2*t[p].tag.val[2][2]%mod)%mod;
 t[i].tag=t[i].tag*t[p].tag;

 i=p*2+1;
 k1=t[i].s1;
 k2=t[i].s2;
 t[i].s1=((ll)k1*t[p].tag.val[1][1]%mod+(ll)k2*t[p].tag.val[2][1]%mod)%mod;
 t[i].s2=((ll)k1*t[p].tag.val[1][2]%mod+(ll)k2*t[p].tag.val[2][2]%mod)%mod;
 t[i].tag=t[i].tag*t[p].tag;

 t[p].tag=e;
}

void change(int p,int l,int r,int x,int y,int z)
{int k1,k2;

 if(l>y || r<x) return;
 if(l>=x && r<=y)
 {	t[p].tag=t[p].tag*w;
	k1=t[p].s1;
	k2=t[p].s2;
	t[p].s1=((ll)k1*w.val[1][1]%mod+(ll)k2*w.val[2][1]%mod)%mod;
	t[p].s2=((ll)k1*w.val[1][2]%mod+(ll)k2*w.val[2][2]%mod)%mod;
	//cout<<p<<" "<<l<<" "<<r<<" "<<t[p].s1<<" "<<t[p].s2<<endl;
	return;
 }
 push_down(p);
 change(p*2,l,(l+r)/2,x,y,z);
 change(p*2+1,(l+r)/2+1,r,x,y,z);
 t[p].s1=(t[p*2].s1+t[p*2+1].s1)%mod;
 t[p].s2=(t[p*2].s2+t[p*2+1].s2)%mod;
}

int query(int p,int l,int r,int x,int y)
{if(l>y || r<x) return 0;
 if(l>=x && r<=y) return t[p].s1;
 push_down(p);
 return (query(p*2,l,(l+r)/2,x,y)+query(p*2+1,(l+r)/2+1,r,x,y))%mod;
}

int calc(int x)
{if(x==0) return 0;
 if(x==1 || x==2) return 1;
 w=fpow(g,x-2);
 return (w.val[1][1]+w.val[2][1])%mod;
}

int main()
{int i,j,opt,x,y,z;
 
 scanf("%d%d",&n,&nq);
 
 g.val[1][1]=1;
 g.val[1][2]=1;
 g.val[2][1]=1;
 
 e.val[1][1]=1;
 e.val[2][2]=1;
 for(i=1;i<=n;i++)
 {	scanf("%d",&x);
 	a[i]=calc(x);
 	b[i]=calc(x-1);
 }
 //for(i=1;i<=n;i++) cout<<a[i]<<" "<<b[i]<<endl;
 build(1,1,n);
 for(i=1;i<=nq;i++)
 {	scanf("%d",&opt);
 	if(opt==1)
 	{	scanf("%d%d%d",&x,&y,&z);
 		w=fpow(g,z);
 		//cout<<"## "<<endl<<w.val[1][1]<<" "<<w.val[1][2]<<endl<<w.val[2][1]<<" "<<w.val[2][2]<<endl;
 		change(1,1,n,x,y,z);
 	}
 	else
 	{	scanf("%d%d",&x,&y);
 		ans=query(1,1,n,x,y);
 		printf("%d\n",ans);
 	}
 }
 return 0;
}