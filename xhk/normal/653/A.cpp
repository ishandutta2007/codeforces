#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int n,ans;
int a[100010];

int check(int i,int j)
{if(i-j>2 || j-i>2) return 1;
 return 0;
}

int main()
{int i,j,k,flag;
 
 ans=0;
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
 	for(j=i+1;j<=n;j++)
 		for(k=j+1;k<=n;k++)
 		{	flag=1;
		 	if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k]) flag=0;
 			if(check(a[i],a[j]) || check(a[i],a[k]) || check(a[j],a[k])) flag=0;
 			if(flag) ans=1;
 		}
 if(ans==1)
 	printf("YES\n");
 else
 	printf("NO\n");
 return 0;
}