#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
__int64 sl[N],a[N],z;
int fi[N],l,d[N],ne[N],f[N],num,b[N],zz[N],n,m,x,y;
void jb(int x,int y,__int64 z)
{
	ne[++num]=fi[x];
	fi[x]=num;
	zz[num]=y;
	sl[num]=z;
}
void up(int x)
{
	if (x==1)return;
	if (a[f[x]]<a[f[x/2]])
	 {
	 	swap(f[x],f[x/2]);
	 	swap(d[f[x]],d[f[x/2]]);
	 	up(x/2);
	 }
}
void down(int x)
{
	int i=x;
	if (x*2<=l&&a[f[x]]>a[f[x*2]])i=x*2;
	if (x*2<l&&a[f[i]]>a[f[x*2+1]])i=x*2+1;
	if (i!=x)
	 {
	 	swap(f[x],f[i]);
	 	swap(d[f[x]],d[f[i]]);
	 	down(i);
	 }
}
int main()
{
	scanf("%d%d",&n,&m);
	while (m--)
	 {
	 	cin>>x>>y>>z;
	 	jb(x,y,z);jb(y,x,z);
	 }
	for (int i=1;i<=n;i++)cin>>a[i];
	l=n;
	for (int i=1;i<=n;i++)f[i]=d[i]=i;
	for (int i=n/2;i;i--)down(i);
	for (int k=1;k<=n;k++)
	 {
	 	int kkk=f[1];
	 	d[kkk]=-1;
	 	f[1]=f[l--];
	 	d[f[1]]=1;
	 	down(1);
	 	for (int j=fi[kkk];j;j=ne[j])
	 	 if (d[zz[j]]!=-1&&a[zz[j]]>a[kkk]+sl[j]*2)
	 	  {
	 	  	a[zz[j]]=a[kkk]+sl[j]*2;
	 	  	up(d[zz[j]]);
	 	  }
	 }
	for (int i=1;i<=n;i++)cout<<a[i],putchar(' '); 
}