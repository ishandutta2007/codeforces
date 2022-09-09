#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int base=1e9;
const int mask=1<<30;
void p(ll a, ll b){ if(!a) printf("%lld\n",b);else printf("%lld%09lld\n",a,b);}
const int N=600050;
int kmp[N],jmp[N],stk[N],ssz,arr[N];
char s[N];
int main()
{
	ll a=0,b=0,sum=0;
	int n;
	map<int,int> cnt;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		char c;int w;
		scanf("\n%c %i",&c,&w);
		c-='a';c=(c+b%26+a%26*base%26)%26;c+='a';
		w=w^((b%mask+a%mask*base%mask)%mask);
		arr[i]=w;s[i]=c;
		while(ssz && arr[stk[ssz]]>=w) ssz--;
		stk[++ssz]=i;
		kmp[i]=kmp[i-1];
		while(kmp[i] && s[kmp[i]+1]!=c) kmp[i]=kmp[kmp[i]];
		if(i>1 && s[kmp[i]+1]==c) kmp[i]++;
		if(i>1) jmp[i-1]=s[kmp[i-1]+1]==c?jmp[kmp[i-1]]:kmp[i-1];
		while(cnt.size() && cnt.rbegin()->first>w)
		{
			pair<int,int> p=*cnt.rbegin();
			cnt.erase(--cnt.end());
			sum-=(ll)(p.first-w)*p.second;
			cnt[w]+=p.second;
		}
		int sz=i-1;
		while(sz)
		{
			if(s[sz+1]!=c)
			{
				int j=lower_bound(stk+1,stk+1+ssz,i-sz)-stk;
				cnt[arr[stk[j]]]--;
				sum-=arr[stk[j]];
				sz=kmp[sz];
			}
			else sz=jmp[sz];
		}
		if(s[1]==c) cnt[w]++,sum+=w;
		b+=sum;a+=b/base;b%=base;
		p(a,b);
	}
	return 0;
}