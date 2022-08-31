#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double ld;
#define SZ 1234567
#define pb push_back
int n,a[SZ],q,qa[SZ],ql[SZ],qr[SZ],qid[SZ],Q=0,aa[SZ],ss[SZ],sn=0,bl;
bool cmp(int a,int b)
{
	if(ql[a]/bl!=ql[b]/bl)
	return ql[a]/bl<ql[b]/bl;
	return qr[a]>qr[b];
}
int l[SZ],r[SZ];
inline void del(int x) //delete
{
	r[l[x]]=r[x];
	l[r[x]]=l[x];
}
#define Del(x) (del(aid[x]))
inline int rev(int x) //reverse
{
	int ans=2147483647;
	if(r[x]<=n) ans=min(ans,aa[r[x]]-aa[x]);
	if(l[x]>=1) ans=min(ans,aa[x]-aa[l[x]]);
	r[l[x]]=x; l[r[x]]=x;
	return ans;
}
#define Rev(x) (rev(aid[x]))
int aidr[SZ],aid[SZ];
bool cmp2(int x,int y) {return a[x]<a[y];}
namespace FF
{
char ch,B[1<<15],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
int aa,bb;int F(){
	//int x; scanf("%d",&x); return x;
    while(ch=getc(),!isd(ch)&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';return bb?aa:-aa;
}
}
#define gi FF::F()
int hza[SZ],tb[100005][318];
int main()
{
	n=gi;
	for(int i=1;i<=n;i++)
		aa[i]=a[i]=gi,aidr[i]=i;
	sort(aa+1,aa+1+n);
	sort(aidr+1,aidr+1+n,cmp2);
	for(int i=1;i<=n;i++)
		aid[aidr[i]]=i;
	q=gi;
	bl=n/sqrt(n+q);
	if(bl<1) bl=1;
	for(int i=1;i<=n;i++) tb[i][1]=2147483647;
	for(int j=2;j<=bl;j++)
	{
		for(int i=1;i+j-1<=n;i++)
			tb[i][j]=min(min(tb[i][j-1],tb[i+1][j-1]),abs(a[i]-a[i+j-1]));
	}
	for(int i=1;i<=q;i++)
	{
		ql[i]=gi,qr[i]=gi;
		if(qr[i]-ql[i]+1<=bl)
		{
			qa[i]=tb[ql[i]][qr[i]-ql[i]+1];
			continue;
		}
		qid[++Q]=i;
	}
	sort(qid+1,qid+1+Q,cmp);
	for(int i=1;i<=Q;i++)
	{
		int ls=i;
		for(int j=i;ql[qid[i]]/bl==ql[qid[j]]/bl;j++)ls=j;
		//cons [i,ls]
		int p=1e9;
		for(int j=i;j<=ls;j++)p=min(p,ql[qid[j]]);
		int q=p+bl;
		if(q>n) q=n;
		for(int _=0;_<=n+1;_++)
			l[_]=_-1,r[_]=_+1;
		for(int j=1;j<q;j++) Del(j);
		for(int j=n;j>q;--j) Del(j);
		hza[q]=2147483647;
		for(int j=q+1;j<=n;j++)
			hza[j]=min(hza[j-1],Rev(j));
		for(int j=q-1;j>=p;j--) Rev(j);
		int r=n;
		for(int j=i;j<=ls;j++)
		{
			while(r>qr[qid[j]]) Del(r--);
			for(int g=p;g<=q;++g) Del(g);
			//back [q,...]
			int ca=hza[qr[qid[j]]];
			for(int s=q;s>=ql[qid[j]];s--)
				ca=min(ca,Rev(s));
			qa[qid[j]]=ca;
			for(int s=ql[qid[j]]-1;s>=p;s--)
				Rev(s);
		}
		i=ls;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",qa[i]);
}