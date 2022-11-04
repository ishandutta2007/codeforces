#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int p,k,mod=1000000007,ans;
int used[2000010];

int fpow(int i,int j)
{int ret;
 if(j==0) return 1;
 ret=fpow(i,j/2);
 ret=(long long)ret*ret%mod;
 if(j%2==1)
 	ret=(long long)ret*i%mod;
 return ret;
}

int main()
{int i,j,s;
 
 scanf("%d%d",&p,&k);
 if(k==0)
 {	ans=fpow(p,p-1);
 	printf("%d\n",ans);
 	return 0;
 }
 
 ans=1;
 for(i=1;i<p;i++)
 	if(used[i]==0)
 	{	s=1;
 		used[i]=1;
 		j=(long long)i*k%p;
 		while(used[j]==0)
 		{	used[j]=1;
 			s++;
			j=(long long)j*k%p;
 		}
 		ans=(long long)ans*p%mod;
 	}
 if(k==1)
 	ans=(long long)ans*p%mod;
 
 printf("%d\n",ans);
 
 return 0;
}