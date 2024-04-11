#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
#define SZ 666666
int n,k,sa[SZ],t[SZ],rank[SZ],qzh_[SZ],tmpsa[SZ],tmpr[SZ],h[SZ];
char s[SZ];
bool same(int a,int b,int p) {return t[a]==t[b]&&t[a+p]==t[b+p];}
void getsa(int m=500)
{
	s[++n]=0;
    for(int i=0;i<n;i++) rank[i]=s[i], ++qzh_[rank[i]];
    for(int i=1;i<m;i++) qzh_[i]+=qzh_[i-1];
    for(int i=n-1;i>=0;i--) sa[--qzh_[rank[i]]]=i;
    for(int j=1;j<=n;j<<=1)
    {
        int cur=-1;
        for(int i=n-j;i<n;i++) tmpsa[++cur]=i;
        for(int i=0;i<n;i++) if(sa[i]>=j) tmpsa[++cur]=sa[i]-j;
        for(int i=0;i<n;i++) tmpr[i]=rank[tmpsa[i]];
        for(int i=0;i<m;i++) qzh_[i]=0;
        for(int i=0;i<n;i++) ++qzh_[tmpr[i]];
        for(int i=1;i<m;i++) qzh_[i]+=qzh_[i-1];
        for(int i=n-1;i>=0;i--) t[i]=rank[i], sa[--qzh_[tmpr[i]]]=tmpsa[i];
        m=0;
        for(int i=0;i<n;i++)
            rank[sa[i]]=(i>0&&same(sa[i],sa[i-1],j))?m:++m;
        ++m;
    }
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    int p=0;
    for(int i=0;i<n;i++)
    {
        if(p) --p;
        int ls=sa[rank[i]-1];
        while(s[ls+p]==s[i+p]) p++;
        h[rank[i]]=p;
    }
    --n;
    for(int i=1;i<=n;i++) sa[i-1]=sa[i];
    for(int i=0;i<n;i++) rank[sa[i]]=i;
    for(int i=2;i<=n;i++) h[i-1]=h[i];
    h[n]=sa[n]=h[0]=0;
}
int qzh[SZ],dy[2333],gs[SZ],pos[SZ];
int ss[SZ],sn=0;
typedef pair<int,int> pii;
pii qss[SZ];
int query(int l,int r)
{
	if(l>r) return 0;
	return upper_bound(qss,qss+1+n,pii(qzh[l],min(gs[l]-1,r+1)))-qss-1-pos[l];
}
int main()
{
	dy['(']=1; dy[')']=-1;
    scanf("%*d%s",s);
    n=strlen(s); getsa();
    for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+dy[s[i-1]];
    for(int i=n;i>=0;i--)
    {
    	int x=qzh[i];
    	while(sn&&qzh[ss[sn]]>=x) --sn;
    	if(!sn) gs[i]=n+1;
    	else gs[i]=ss[sn];
    	ss[++sn]=i;
	}
	for(int i=0;i<=n;i++) qss[i]=pii(qzh[i],i);
	sort(qss,qss+1+n);
	for(int i=0;i<=n;i++) pos[qss[i].second]=i;
	long long ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=query(sa[i],n-1);
		ans-=query(sa[i],sa[i]+h[i]-1);
	}
	printf("%I64d\n",ans);
}