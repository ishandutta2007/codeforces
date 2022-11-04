#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
const int inf=1e9;

struct unit
{int mi,se,cnt,tag;
 long long s;
};
struct unit t[800010];

int n,maxn;
int a[200010];
long long ans;
vector<int> w[200010],b[200010];

void update(int p)
{t[p].s=t[p*2].s+t[p*2+1].s;
 t[p].se=inf;
 t[p].mi=min(t[p*2].mi,t[p*2+1].mi);
 t[p].cnt=0;
 if(t[p*2].mi==t[p].mi) t[p].cnt+=t[p*2].cnt;
 if(t[p*2+1].mi==t[p].mi) t[p].cnt+=t[p*2+1].cnt;
 if(t[p*2].mi<t[p*2+1].mi)
	t[p].se=min(t[p*2].se,t[p*2+1].mi);
 else if(t[p*2].mi>t[p*2+1].mi)
 	t[p].se=min(t[p*2].mi,t[p*2+1].se);
 else
 	t[p].se=min(t[p*2].se,t[p*2+1].se);
}

void build(int p,int l,int r)
{if(l==r)
 {	t[p].mi=l;
 	t[p].se=inf;
 	t[p].cnt=1;
 	t[p].s=l;
 	return;
 }
 build(p*2,l,(l+r)/2);
 build(p*2+1,(l+r)/2+1,r);
 update(p);
}

void modify(int p,int l,int r,int z)
{if(t[p].mi>=z) return;
 if(t[p].se>z)
 {	t[p].s+=(ll)(z-t[p].mi)*t[p].cnt;
 	t[p].mi=z;
 	t[p].tag=max(t[p].tag,z);
 	return;
 }
 z=max(z,t[p].tag);
 t[p].tag=0;
 modify(p*2,l,(l+r)/2,z);
 modify(p*2+1,(l+r)/2+1,r,z);
 update(p);
}

void push_down(int p,int l,int r)
{if(!t[p].tag) return;
 modify(p*2,l,(l+r)/2,t[p].tag);
 modify(p*2+1,(l+r)/2+1,r,t[p].tag);
 t[p].tag=0;
}

void change_max(int p,int l,int r,int x,int y,int z)
{if(l>y || r<x || x>y) return;
 if(l>=x && r<=y)
 {	modify(p,l,r,z);
 	return;
 }
 push_down(p,l,r);
 change_max(p*2,l,(l+r)/2,x,y,z);
 change_max(p*2+1,(l+r)/2+1,r,x,y,z);
 update(p);
}

int main()
{int i,j;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {	scanf("%d",&a[i]);
 	maxn=max(maxn,a[i]);
 }
 for(i=1;i<=maxn;i++)
 	for(j=i;j<=maxn;j+=i)
 		b[j].push_back(i);
 for(i=1;i<=n;i++)
 	for(j=0;j<b[a[i]].size();j++)
 		w[b[a[i]][j]].push_back(i);
 build(1,1,n);
 for(i=maxn+1;i>=1;i--)
 {	ans+=(ll)n*(n+1)/2-((ll)n*(n+1)-t[1].s);
 	if(w[i-1].size()<2) continue;
 	change_max(1,1,n,1,w[i-1][0],w[i-1][w[i-1].size()-2]);
 	change_max(1,1,n,w[i-1][0]+1,w[i-1][1],w[i-1][w[i-1].size()-1]);
 	change_max(1,1,n,w[i-1][1]+1,n,n+1);
 }
 printf("%I64d\n",ans);
 return 0;
}