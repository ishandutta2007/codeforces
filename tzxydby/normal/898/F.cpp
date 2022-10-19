#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005;
const int P=10;
const int mod1=20040911;
const int mod2=1000000009;
int p1[N]={1},p2[N]={1},h1[N],h2[N],n;
char s[N];
inline int gh1(int a,int b)
{
	return (h1[b]-h1[a-1]*p1[b-a+1]%mod1+mod1)%mod1;
}
inline int gh2(int a,int b)
{
	return (h2[b]-h2[a-1]*p2[b-a+1]%mod2+mod2)%mod2;
}
inline int can(int a,int b)
{
	if(!a)
		return 0;
	if(b-a!=1&&s[a+1]=='0')
		return 0;
	if(b!=n-1&&s[b+1]=='0')
		return 0;	
	return 1;
} 
inline void out(int a,int b)
{
	for(int i=1;i<=a;i++)
		putchar(s[i]);	
	putchar('+');
	for(int i=a+1;i<=b;i++)
		putchar(s[i]);
	putchar('=');
	for(int i=b+1;i<=n;i++)
		putchar(s[i]);
	exit(0);
} 
main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		h1[i]=(h1[i-1]*P%mod1+s[i]-'0')%mod1;
	for(int i=1;i<=n;i++)
		p1[i]=p1[i-1]*P%mod1;
	for(int i=1;i<=n;i++)
		h2[i]=(h2[i-1]*P%mod2+s[i]-'0')%mod2;
	for(int i=1;i<=n;i++)
		p2[i]=p2[i-1]*P%mod2;
	for(int i=n-1;i>=2;i--)
	{
		if(i<n-i)
			continue;
		int sum1=gh1(i+1,n),sum2=gh2(i+1,n),len=n-i;
		if((gh1(1,len)+gh1(len+1,i))%mod1==sum1&&(gh2(1,len)+gh2(len+1,i))%mod2==sum2
		&&can(len,i))
			out(len,i);
		if((gh1(1,len-1)+gh1(len,i))%mod1==sum1&&(gh2(1,len-1)+gh2(len,i))%mod2==sum2
		&&can(len-1,i))
			out(len-1,i);
		if((gh1(1,i-len)+gh1(i-len+1,i))%mod1==sum1&&(gh2(1,i-len)+gh2(i-len+1,i))%mod2==sum2
		&&can(i-len,i))
			out(i-len,i);
		if((gh1(1,i-len+1)+gh1(i-len+2,i))%mod1==sum1&&(gh2(1,i-len+1)+gh2(i-len+2,i))%mod2==sum2
		&&can(i-len+1,i))
			out(i-len+1,i);
	}
	return 0;
}