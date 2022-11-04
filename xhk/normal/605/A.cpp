#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans;
int a[100010],b[100010];

int main()
{int i,j,s;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {	scanf("%d",&a[i]);
 	b[a[i]]=i;
 }
 s=0;
 for(i=1;i<=n;i++)
 {	if(b[i]>b[i-1])
 		s++;
 	else
	{	ans=max(ans,s);
		s=1;
	}
 }
 ans=max(ans,s);
 cout<<n-ans<<endl;
 return 0;
}