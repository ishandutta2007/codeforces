#include<bits/stdc++.h>
using namespace std;

int n,sa,sb,t,ans;
char a[1000010];

void work()
{int i,j,s=0,s1=0,ss=0,s2=0;
 j=2;
 for(i=n;i>=2;i--)
 {	ss+=sa;
 	if(a[i]=='w') ss+=sb;
	ss++;
	s2++;
 }
 for(i=1;i<=n;i++)
 {	if(a[i]=='w') s+=sb;	
 	s++;
 	s1++;
 	while((j<=i) || (s+(i-1)*sa+ss>t && j<=n)) 
 	{	ss-=sa;
 		ss--;
	 	if(a[j]=='w') ss-=sb;
	 	s2--;
	 	j++;
	}
	if(j<=n)
		ans=max(ans,n-j+1+i);
	else if(s<=t)
		ans=max(ans,i);
	s+=sa;
 }
}

int main()
{int i,j;
 
 scanf("%d%d%d%d",&n,&sa,&sb,&t);
 scanf("%s",a+1);
 work();
 for(i=2;i<=(2+n)/2;i++)
 	swap(a[i],a[n+2-i]);
 work();
 cout<<ans<<endl;
 return 0;
}