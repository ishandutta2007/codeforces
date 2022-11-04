#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

int n,ans,tot,n1;
int a[200010],w[200100],b[200100];
map<pair<int,int>,int> h;

int check(int i)
{if(i<=0 || i>=n) return 1;
 if(i&1)
 	return a[i]<a[i+1];
 else
 	return a[i]>a[i+1];
}

void update(int i,int j)
{if(i>j) swap(i,j);
 if(h.find(make_pair(i,j))==h.end())
 {	ans++;
 	h[make_pair(i,j)]=1;
 }
}
 
int work(int i,int j)
{int k,flag;
 if(i<=0 || i>n || j<=0 || j>n) return 0;
 swap(a[i],a[j]);
 flag=1;
 for(k=1;k<n;k++) 
 	if(!check(k))
 	{	flag=0;
 		break;
 	}
 swap(a[i],a[j]);
 return flag;
}
 
int main()
{int i,j;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 	scanf("%d",&a[i]);
 for(i=1;i<n;i++)
 	if(!check(i)) w[++tot]=i;
 if(tot>4)
 {	printf("%d\n",0);	
 	return 0;
 }
 if(tot==4)
 {	swap(a[w[2]],a[w[4]]);
 	ans=1;
 	for(i=1;i<n;i++)
 		if(!check(i))
 		{	ans=0;
 			break;
 		}
 	swap(a[w[2]],a[w[4]]);	
 }
 else if(tot==3)
 {	for(i=1;i<=tot;i++)
 	{	b[++n1]=w[i];
 		b[++n1]=w[i]+1;
	}
	for(i=1;i<=n1;i++)
		for(j=i+1;j<=n1;j++)
			if(work(b[i],b[j])) update(b[i],b[j]);
 }
 else if(tot==2)
 {	if(w[2]!=w[1]+1)
 	{	for(i=1;i<=tot;i++)
 		{	b[++n1]=w[i];
 			b[++n1]=w[i]+1;
		}	
		for(i=1;i<=n1;i++)	
			for(j=i+1;j<=n1;j++)
				if(work(b[i],b[j])) update(b[i],b[j]);
	}
	else
	{	for(i=1;i<=n;i++)
		{	swap(a[i],a[w[2]]);
			if(check(i-1) && check(i) && check(w[1]-1) && check(w[1]) && check(w[2])) update(i,w[2]);
			swap(a[i],a[w[2]]);
		
			if(w[2]>=n) continue;
			swap(a[i],a[w[2]+1]);
			if(check(i-1) && check(i) && check(w[1]) && check(w[1]-1) && check(w[1]+1) && check(w[2]+1)) update(i,w[2]+1);
			swap(a[i],a[w[2]+1]);
		}
	}
 }
 else
 {	for(i=1;i<=n;i++)
	{	swap(a[i],a[w[1]]);
		if(check(i-1) && check(i) && check(w[1]) && check(w[1]-1)) update(i,w[1]);
		swap(a[i],a[w[1]]);
		
		if(w[1]+1>n) continue;
		swap(a[i],a[w[1]+1]);
		if(check(i-1) && check(i) && check(w[1]+1) && check(w[1]) && check(w[1]-1)) update(i,w[1]+1);
		swap(a[i],a[w[1]+1]);
	}
 }
 cout<<ans<<endl;
}