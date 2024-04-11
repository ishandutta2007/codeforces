#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define SZ 666666
int n,m;
typedef pair<long long,char> pic;
pic as[SZ],bs[SZ];
#define f_ first
#define s_ second
void m_1()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(as[i].s_==bs[1].s_&&as[i].f_>=bs[1].f_) ans+=as[i].f_-bs[1].f_+1;
	}
	printf("%I64d\n",ans);
}
void m_2()
{
	long long ans=0;
	for(int i=1;i+1<=n;i++)
	{
		if(as[i].s_==bs[1].s_&&as[i].f_>=bs[1].f_&&as[i+1].s_==bs[2].s_&&as[i+1].f_>=bs[2].f_) ++ans;
	}
	printf("%I64d\n",ans);
}
int ms=0,ml[SZ],mr[SZ];
struct HashKMP
{
pic s[SZ+1];
int n,next[SZ+3];
void gnext()
{
	n=0;
	while(s[n].s_) ++n;
    next[0]=-1;
    int j=-1;
    for(int i=1;i<n;i++)
    {
        while(j!=-1&&s[i].s_!=s[j+1].s_) j=next[j];
        if(s[i].s_==s[j+1].s_) ++j;
        next[i]=j;
    }
}
void kmp(pic* a)
{
    int j=-1;
    for(int i=0;a[i].s_;i++)
    {
        while(j!=-1&&s[j+1]!=a[i]) j=next[j];
        if(s[j+1]==a[i]) ++j;
        if(j==n-1) ++ms, ml[ms]=i-n+1, mr[ms]=i+2;
    }
}
}ha;
pic hb[SZ];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a; char b[3];
		scanf("%d-%s",&a,b);
		if(i>1&&as[i-1].s_==b[0])
		{
			as[i-1].f_+=a; --i; --n; continue;
		}
		as[i]=pic(a,b[0]);
	}
	for(int i=1;i<=m;i++)
	{
		int a; char b[3];
		scanf("%d-%s",&a,b);
		if(i>1&&bs[i-1].s_==b[0])
		{
			bs[i-1].f_+=a; --i; --m; continue;
		}
		bs[i]=pic(a,b[0]);
	}
	if(m==1) {m_1(); return 0;}
	if(m==2) {m_2(); return 0;}
	for(int i=2;i<=m-1;i++) ha.s[i-2]=bs[i];
	ha.gnext();
	for(int i=1;i<=n;i++) hb[i-1]=as[i];
	ha.kmp(hb);
	long long ans=0;
	for(int i=1;i<=ms;i++)
	{
		int a=ml[i],b=mr[i];
		if(a<1||b<1||a>n||b>n) continue;
		if(as[a].s_==bs[1].s_&&as[a].f_>=bs[1].f_);else continue;
		if(as[b].s_==bs[m].s_&&as[b].f_>=bs[m].f_);else continue;
		++ans;
	}
	printf("%I64d\n",ans);
}