#include <stdio.h>
#define ll long long
const int mod=1e9+7;
const int N=100050;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int inv(int x){ return pow(x,mod-2);}
int F[N],I[N];
int get(int n, int k){ return (ll)F[n]*I[n-k]%mod*I[k]%mod;}
int main()
{
	int f,w,h,i,j,all=0,good=0;
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	I[N-1]=inv(F[N-1]);for(i=N-2;i>=0;i--) I[i]=(ll)I[i+1]*(i+1)%mod;
	scanf("%i %i %i",&f,&w,&h);
	if(!f)
	{
		if(w>h) printf("1\n");
		else printf("0\n");
		return 0;
	}
	if(!w) return printf("1\n"),0;
	for(i=1;i<=w;i++)
	{
		if(i-1>0 && i-1<=f)
		{
			w-=i;f-=i-1;
			all+=(ll)get(w+i-1,w)*get(f+i-2,f)%mod;
			if(all>=mod) all-=mod;
			w+=i;f+=i-1;
		}
		if(i<=f)
		{
			w-=i;f-=i;
			all+=(ll)get(w+i-1,w)*get(f+i-1,f)*2%mod;
			if(all>=mod) all-=mod;
			w+=i;f+=i;
		}
		if(i+1<=f)
		{
			w-=i;f-=i+1;
			all+=(ll)get(w+i-1,w)*get(f+i,f)%mod;
			if(all>=mod) all-=mod;
			w+=i;f+=i+1;
		}
	}
	for(i=1;i<=w;i++)
	{
		if(i*(h+1)>w) break;
		if(i-1>0 && i-1<=f)
		{
			w-=i*(h+1);f-=i-1;
			good+=(ll)get(w+i-1,w)*get(f+i-2,f)%mod;
			if(good>=mod) good-=mod;
			w+=i*(h+1);f+=i-1;
		}
		if(i<=f)
		{
			w-=i*(h+1);f-=i;
			good+=(ll)get(w+i-1,w)*get(f+i-1,f)*2%mod;
			if(good>=mod) good-=mod;
			w+=i*(h+1);f+=i;
		}
		if(i+1<=f)
		{
			w-=i*(h+1);f-=i+1;
			good+=(ll)get(w+i-1,w)*get(f+i,f)%mod;
			if(good>=mod) good-=mod;
			w+=i*(h+1);f+=i+1;
		}
	}
	printf("%i\n",(ll)good*inv(all)%mod);
	return 0;
}