#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int inf=2147483647,mod=25000009,seed1=998244353,seed2=1000000009;

struct hash
{int x,y,k,flag,val;
};
struct hash h[25000020];

int n,ans,cnt;
int s[4010],a[4010];

int search(int l,int r,int k,int flag)
{int p;
 
 p=((ll)l*seed1+(ll)r*seed2+(ll)k*13+flag)%mod;
 while(h[p].x && (h[p].x!=l || h[p].y!=r || h[p].k!=k || h[p].flag!=flag))
 {	//cout<<p<<endl;
 	p++;
 	if(p==mod) p=0;
 }
 if(h[p].x)
 	return h[p].val;
 else
 	return inf;
}

void add(int l,int r,int k,int flag,int x)
{int p;
 
 //cnt++;
 //if(cnt%10000==0) cout<<cnt<<endl;
 p=((ll)l*seed1+(ll)r*seed2+(ll)k*13+flag)%mod;
 while(h[p].x && (h[p].x!=l || h[p].y!=r || h[p].k!=k || h[p].flag!=flag))
 {	p++;
 	if(p==mod) p=0;
 }
 h[p].x=l;
 h[p].y=r;
 h[p].k=k;
 h[p].val=x;
 h[p].flag=flag;
}

int work(int l,int r,int k,int flag)
{int ret;
 if(r-l+1<k) return 0;
 //cout<<l<<" "<<r<<" "<<k<<" "<<ret<<endl;
 ret=search(l,r,k,flag);
 //cout<<l<<" "<<r<<" "<<k<<" "<<ret<<endl;
 if(ret!=inf) return ret;
 if(flag==0)
 {	ret=s[l+k-1]-s[l-1]-work(l+k,r,k,1);
 	if(r-l+1>=k+1) ret=max(ret,s[l+k]-s[l-1]-work(l+k+1,r,k+1,1));
 }
 else
 {	ret=s[r]-s[r-k]-work(l,r-k,k,0);
 	if(r-l+1>=k+1) ret=max(ret,s[r]-s[r-k-1]-work(l,r-k-1,k+1,0));
 }
 add(l,r,k,flag,ret);
 return ret;
}

int main()
{int i,j;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
 //n=4000;
 work(1,n,1,0);
 ans=search(1,n,1,0);
 printf("%d\n",ans);
 return 0;
}