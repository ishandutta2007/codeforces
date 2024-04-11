#include <stdio.h>
#include <cstring>
#define ll long long
const int N=1000050;
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int C[26],D[26],F[N],I[N],n;
char a[N],b[N];
/*int Binom(int n, int k)
{
	return (ll)F[n]*I[n-k]%mod*I[k]%mod;
}
int Calc(int n)
{
	int i,j=n,ret=1;
	for(i=0;i<26;i++)
	{
		ret=(ll)ret*Binom(j,C[i])%mod;
		j-=C[i];
	}
	return ret;
}*/
int Solve()
{
	int i,j,m,tmp,ans=0,k=1;
	for(j=0;j<26;j++) D[j]=C[j];
	for(i=0;i<n;i++)
	{
		m=b[i]-'a';
		tmp=0;
		for(j=0;j<m;j++) tmp+=D[j];
		ans=(0ll+ans+(ll)tmp*F[n-i-1]%mod*k%mod)%mod;
		if(!D[m]) break;
		k=(ll)k*D[m]%mod;
		D[m]--;
	}
	for(j=0;j<26;j++) ans=(ll)ans*I[C[j]]%mod;
	return ans;
}
/*int Solve(int lvl, bool rf)
{
	//if(lvl==n) return 0;
	if(!rf) return Calc(n-lvl);
	int top=(b[lvl]-'a'),i;
	int ans=0;
	//printf("%i %i\n",bot,top);
	for(i=0;i<=top;i++)
	{
		if(C[i])
		{
			//printf("%c\n",i+'a');
			C[i]--;
			ans+=(ll)(C[i]+1)*Solve(lvl+1, rf && (i==top))%mod;
			if(ans>mod) ans-=mod;
			C[i]++;
		}
	}
	return ans;
}*/
int main()
{
	int i;
	F[0]=1;
	for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=pow(F[N-1],mod-2);
	for(i=N-2;i>=0;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	scanf("%s",a);
	scanf("%s",b);
	n=strlen(a);
	//while(a[n]<='z' && a[n]>='a') n++;
	//if(a[0]=='n') printf("%i %i\n",n,m);
	for(i=0;i<n;i++) C[a[i]-'a']++;
	int out=Solve();
	for(i=0;i<n;i++) b[i]=a[i];
	out=(0ll+out-Solve()-1+mod)%mod;
	printf("%i\n",out);
	return 0;
}