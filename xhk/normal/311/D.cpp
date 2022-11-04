#include<cstdio>
#include<iostream>
using namespace std;

struct unit
{int now,tag;
 long long s[48];
};
struct unit t[400010];

int n,m,x,y,a[100010];
long long ans=0;

void calc(int p,int num)
{int i,j;
 long long ss=0;

 t[p].s[0]=num;

 for(i=1;i<=47;i++)
 {ss=t[p].s[i-1];

  ss=(ss*t[p].s[i-1])%95542721;

  ss=(ss*t[p].s[i-1])%95542721;

  t[p].s[i]=ss;
 }
}

void build(int p,int l,int r)
{int i,j;

 if(l==r)
 {calc(p,a[l]);
  t[p].now=0;
  t[p].tag=0;
 }
 else
 {build(p*2,l,(l+r)/2);
  build(p*2+1,(l+r)/2+1,r);
  
  for(i=0;i<=47;i++) 
  {t[p].s[i]=0;
   t[p].s[i]=(t[p].s[i]+t[p*2].s[i])%95542721;
   t[p].s[i]=(t[p].s[i]+t[p*2+1].s[i])%95542721;
  }

  t[p].now=0;
  t[p].tag=0;
 }
}

void push_down(int p)
{t[p*2].now=(t[p*2].now+t[p].tag)%48;
 t[p*2].tag=(t[p*2].tag+t[p].tag)%48;
 
 t[p*2+1].now=(t[p*2+1].now+t[p].tag)%48;
 t[p*2+1].tag=(t[p*2+1].tag+t[p].tag)%48;

 t[p].tag=0;
}

void update(int p)
{int i,j,k;
 t[p].tag=0;
 t[p].now=0;
 
 i=t[p*2].now;
 j=t[p*2+1].now;
 
 for(k=0;k<=47;k++)
 {t[p].s[k]=0;
  t[p].s[k]=(t[p].s[k]+t[p*2].s[i])%95542721;
  t[p].s[k]=(t[p].s[k]+t[p*2+1].s[j])%95542721;  
  i=(i+1)%48;
  j=(j+1)%48;
 }

}

void query(int p,int l,int r)
{if(l>y || r<x) return;

 if(x<=l && r<=y)
  ans=(ans+t[p].s[t[p].now%48])%95542721;
 else
 {push_down(p);
  if(x<=(l+r)/2) query(p*2,l,(l+r)/2);
  if(y>=(l+r)/2+1) query(p*2+1,(l+r)/2+1,r);
  //update(p);
 }

}

void change(int p,int l,int r)
{if(l>y || r<x) return;

 if(x<=l && r<=y)
 {t[p].now=(t[p].now+1)%48;
  t[p].tag=(t[p].tag+1)%48;

  return;
 }
 else
 {push_down(p);
  
  if(x<=(l+r)/2) change(p*2,l,(l+r)/2);
  if(y>=(l+r)/2+1) change(p*2+1,(l+r)/2+1,r);
 
  update(p);

 }

}

int main()
{//freopen("seq.in","r",stdin);
 //freopen("seq.out","w",stdout);

 int i,j,f;
 
 scanf("%d",&n);
 
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 
 build(1,1,n);
 
 
 
 scanf("%d",&m);
 
 for(i=1;i<=m;i++)
 {scanf("%d%d%d",&f,&x,&y);
  
  if(f==1)
  {ans=0;
   query(1,1,n);
   ans=ans%95542721;

   printf("%d\n",ans);

  }
  else
   change(1,1,n);
 }
 
 
 return 0;
}