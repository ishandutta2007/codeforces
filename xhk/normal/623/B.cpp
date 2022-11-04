#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,tot;
int a[1000010],b[100010],c[1000010],q[1000010];
long long inf=1e18,sa,sb,ans=inf;

void calc(int i)
{int j,t;
 t=i;
 for(j=2;j*j<=i;j++)
 	if(t%j==0)
 	{	b[++tot]=j;
 		while(t%j==0) t/=j;
 	}
 if(t!=1) b[++tot]=t;	
}

void work(int d)
{int i,j,l=n+1,r=0;
 long long s=0,s1=0,ss=0,s2=0,t=0;
 
 for(i=1;i<=n;i++)
 	if(a[i]%d==0)
 		c[i]=0;
 	else if((a[i]+1)%d==0 || (a[i]-1)%d==0)
	 	c[i]=1;
	else
	{	c[i]=-1;
		l=min(l,i);
		r=max(r,i);
	}
 if(l>r)
 {	s1=0;
 	s2=0;
 	s=0;
 	for(i=1;i<=n;i++)
	 	if(c[i]!=0) s+=sb;
	t=s;
	for(i=1;i<=n;i++)
	{	ans=min(ans,s+s2);
		//cout<<i<<" "<<s<<" "<<s2<<" "<<ans<<endl;
		if(c[i]==1) 
		{	s1+=sb;
			s-=sb;
		}
		s2=min(s2+sa,s1);
	}
	//cout<<ans<<endl;
	s=t;
	s1=0;
	s2=0;
	for(i=n;i>=1;i--)
	{	ans=min(ans,s+s2);
		if(c[i]==1) 
		{	s1+=sb;
			s-=sb;
		}
		s2=min(s2+sa,s1);
	}
 }
 else if(l==1 && r==n)
 	return;
 else	 	
 {	s=inf;
 	s1=0;
 	for(i=0;i<l;i++)
 	{	s=min(s,s1+(long long)(l-i-1)*sa);
 		if(c[i+1]==1) s1+=sb;
 	}
 	ss+=s;
 	s=inf;
 	s1=0;
 	for(i=n+1;i>r;i--)
 	{	s=min(s,s1+(long long)(i-r-1)*sa);
 		if(c[i-1]==1) s1+=sb;
 	}
 	ss+=s;
 	ans=min(ans,ss+(long long)(r-l+1)*sa);
 }
 /*
 cout<<l<<" "<<r<<endl;
 cout<<d<<endl;
 for(i=1;i<=n;i++)
 	cout<<c[i]<<" ";
 cout<<endl;
 */
}

int main()
{int i,j;
 
 scanf("%d%I64d%I64d",&n,&sa,&sb);
 for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 calc(a[1]-1);
 calc(a[1]);
 calc(a[1]+1);
 calc(a[n]-1);
 calc(a[n]);
 calc(a[n]+1);	
 sort(b+1,b+tot+1);
 for(i=1;i<=tot;i++)
 {	if(b[i]!=b[i-1])
 		work(b[i]);
 }
 cout<<ans<<endl;
 return 0;
}