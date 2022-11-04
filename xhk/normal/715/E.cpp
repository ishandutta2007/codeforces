#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
const int mod=998244353;
int n,tot,cnt00,cnt10,cnt01;
int a[310],b[310],used[610],w[310],fac[310],comb[610][610],s[310][310],f[310],g[310],ans[310];
vector<int> q;

int dfs(int i)
{if(used[i]) return 0;
 used[i]=1;
 if(i<=n)
 {	if(!a[i])
 		return i;
 	else
 		return dfs(n+a[i]);
 }
 else
 {	if(!b[i-n])
 		return i;
 	else
 		return dfs(b[i-n]);
 }
}

int main()
{int i,j,k,p;
 
 scanf("%d",&n);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
 {	scanf("%d",&b[i]);
 	if(b[i])
	{	w[b[i]]=i;
 		used[b[i]]=1;
 	}
 }
 k=1;
 for(i=1;i<=n;i++)
 	if(!b[i])
 	{	while(used[k]) k++;
 		w[k]=i;
 		k++;
 	}
 memset(used,0,sizeof(used));	
 for(i=1;i<=n;i++)
 {	if(a[i]) a[i]=w[a[i]];
  	if(b[i]) b[i]=i;
 }	
 for(i=1;i<=n;i++)
	if(a[i]) used[n+a[i]]=1;
 for(i=1;i<=n;i++)
	if(b[i]) used[b[i]]=1;	
 for(i=1;i<=2*n;i++)
 	if(used[i]!=1) q.push_back(i);
 for(i=1;i<=2*n;i++) q.push_back(i);	
 memset(used,0,sizeof(used));
 for(i=0;i<q.size();i++)
 {	p=q[i];
 	if(used[p]==0)
 	{	k=dfs(p);
 		if(!k)
 			tot++;
 		else if(p<=n && k<=n)
 			cnt00++;
 		else if(p<=n && k>n)
 			cnt01++;
 		else if(p>n && k<=n)
 			cnt10++;
 	}	
 }
 fac[0]=1;
 for(i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;	
 for(i=0;i<=2*n;i++)
 {	comb[i][0]=1;
 	for(j=1;j<=i;j++)
	 	comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
 }
 s[0][0]=1;
 for(i=1;i<=n;i++)
 	for(j=1;j<=i;j++)
 		s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*(i-1)%mod)%mod;
 if(cnt00)		
 {	for(i=0;i<=cnt10;i++)
 		g[i]=(ll)fac[cnt00]*fac[i]%mod*comb[i+cnt00-1][cnt00-1]%mod;
 }
 else
 	g[0]=1;
 for(j=0;j<=cnt10;j++)
 	for(k=0;k<=cnt10-j;k++)
 		f[j]=(f[j]+(ll)s[cnt10-k][j]*g[k]%mod*comb[cnt10][k]%mod)%mod;	
 for(i=0;i<=n-tot;i++)
 	for(j=0;j<=cnt10 && j<=i;j++)
	 	ans[i+tot]=(ans[i+tot]+(ll)f[j]*s[cnt01+cnt00][i-j]%mod)%mod;
 for(i=0;i<n;i++)
 {	printf("%d",ans[n-i]);
	printf("%c",i!=n-1?' ':'\n');
 }
 return 0;
}