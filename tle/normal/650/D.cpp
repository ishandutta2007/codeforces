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
int inf=1000000000;
#define SZ 666666
int n,a[SZ],len,lt[SZ],L[SZ],R[SZ],q,ql[SZ],qr[SZ],col[SZ];
struct Tuple {int a,b,id;} qs[SZ];
bool c1(Tuple a,Tuple b) {return a.a<b.a;}
bool c2(Tuple a,Tuple b) {return a.a>b.a;}
bool c3(Tuple a,Tuple b) {return a.id<b.id;}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=q;i++) scanf("%d %d",&qs[i].a,&qs[i].b), qs[i].id=i;
	int cur;
	sort(qs+1,qs+1+q,c1);
	cur=1; len=0;
	memset(lt,0,sizeof(lt));
	for(int i=1;i<=n;i++)
	{
		int cl;
		while(cur<=q&&qs[cur].a==i)
		{
			int ans,c=qs[cur].b;
			if(!len||c>lt[len]) ans=len+1;
			else ans=lower_bound(lt+1,lt+1+len,c)-lt;
			ql[qs[cur].id]=ans;
			++cur;
		}
		if(i!=1)
		{
			if(a[i]>lt[len]) lt[cl=++len]=a[i];
			else lt[cl=lower_bound(lt+1,lt+1+len,a[i])-lt]=a[i];
		}
		else lt[1]=a[1], cl=1, len=1;
		L[i]=cl;
	}
	int lis=len;
	sort(qs+1,qs+1+q,c2);
	for(int i=1;i<=n;i++) a[i]=inf-a[i];
	cur=1; len=0;
	memset(lt,0,sizeof(lt));
	for(int i=n;i>=1;i--)
	{
		int cl;
		while(cur<=q&&qs[cur].a==i)
		{
			int ans,c=inf-qs[cur].b;
			if(!len||c>lt[len]) ans=len+1;
			else ans=lower_bound(lt+1,lt+1+len,c)-lt;
			qr[qs[cur].id]=ans;
			++cur;
		}
		if(i!=n)
		{
			if(a[i]>lt[len]) lt[cl=++len]=a[i];
			else lt[cl=lower_bound(lt+1,lt+1+len,a[i])-lt]=a[i];
		}
		else lt[1]=a[n], cl=1, len=1;
		R[i]=cl;
	}
	//for(int i=1;i<=n;i++) a[i]=inf-a[i];
	for(int i=1;i<=n;i++)
	{
		if(L[i]+R[i]-1!=lis) continue;
		col[L[i]]++;
	}
	sort(qs+1,qs+1+q,c3);
	for(int p=1;p<=q;p++)
	{
		int i=qs[p].a;
		int a1=ql[p]+qr[p]-1;
		bool met=L[i]+R[i]-1==lis&&col[L[i]]==1;
		int a2=lis-met;
		printf("%d\n",max(a1,a2));
	}
}