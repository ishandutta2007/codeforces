#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=300000,mod=1000000007;
int n,num,ans;
int u[300010],prime[300010],mp[300010],a[300010],fac[300010],inv_fac[300010],c[300010];
vector<int> w[300010];

int fpow(int i,int j)
{int ret=1;
 for(;j;i=(ll)i*i%mod,j/=2)
 	if(j&1) ret=(ll)ret*i%mod;
 return ret;
}

void prework()
{int i,j;
 
 for(i=2;i<=maxn;i++)
 {	if(!u[i])
 	{	prime[++num]=i;
 		mp[i]=i;
 	}
 	for(j=1;j<=num;j++)
 	{	if(i*prime[j]>maxn) break;
 		u[i*prime[j]]=1;
 		mp[i*prime[j]]=prime[j];
 		if(i%prime[j]==0) break;
 	}
 }
}

int calc(int k)
{return (((ll)c[n-1]-c[n-k])-(k<n?c[n-k-1]:0))%mod;
}

int main()
{int i,j,k,p,s;
 
 prework();
 scanf("%d",&n);
 fac[0]=1;
 for(i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
 inv_fac[n]=fpow(fac[n],mod-2);
 for(i=n-1;i>=0;i--) inv_fac[i]=(ll)inv_fac[i+1]*(i+1)%mod;
 c[0]=1;
 for(i=1;i<=n-1;i++) c[i]=(c[i-1]+(ll)fac[n-1]*inv_fac[i]%mod*inv_fac[n-1-i]%mod)%mod;
 for(i=1;i<=n;i++)
 {	scanf("%d",&a[i]);
 	k=a[i];
 	while(k!=1)
 	{	p=mp[k];
 		s=0;
 		while(mp[k]==p)
 		{	s++;
 			k/=p;
 		}
 		w[p].push_back(s);
 	}
 }
 for(i=2;i<=maxn;i++)
 {	if(w[i].empty()) continue;
 	sort(w[i].begin(),w[i].end());
 	//for(j=0;j<w[i].size();j++) cout<<w[i][j]<<" ";
 	//cout<<endl;
 	k=n-w[i].size();
 	for(j=0;j<w[i].size();j++)
 	{	k++;
 		ans=(ans+(ll)w[i][j]*calc(k)%mod)%mod;
 		//cout<<k<<" "<<ans<<" "<<w[i][j]<<" "<<calc(k)<<endl;
 		//cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
 	}
 }
 printf("%d\n",(ans+mod)%mod);
 return 0;
}