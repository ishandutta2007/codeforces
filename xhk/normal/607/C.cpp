#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int n,seed=314159,mod=998244353;
int f[1000010],g[1000010],fac[1000010];
char a[1000010],b[1000010];

int main()
{int i,j,flag;
 
 scanf("%d",&n);
 n--;
 scanf("%s",a+1);
 scanf("%s",b+1);
 for(i=1;i<=n/2;i++)
 	swap(b[i],b[n+1-i]);
 for(i=1;i<=n;i++)
 	if(b[i]=='S')
 		b[i]='N';
 	else if(b[i]=='N')
	 	b[i]='S';
	else if(b[i]=='E')
		b[i]='W';
	else
		b[i]='E';
 //for(i=1;i<=n;i++)
 //	cout<<b[i];
 //cout<<endl;	 	 			 	
 fac[0]=1;
 for(i=1;i<=n;i++)
 	fac[i]=(long long)fac[i-1]*seed%mod;
 for(i=1;i<=n;i++)
 {	f[i]=((long long)f[i-1]*seed%mod+a[i])%mod;
 	g[i]=((long long)g[i-1]*seed%mod+b[i])%mod;
 }
 flag=1;
 for(i=1;i<=n;i++)
 	if(g[i]==((f[n]-(long long)f[n-i]*fac[i]%mod)%mod+mod)%mod)
 	{	flag=0;
 		break;
 	}
 if(flag)
 	printf("YES\n");
 else
 	printf("NO\n");
 return 0;
}