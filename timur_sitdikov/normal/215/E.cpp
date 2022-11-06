#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back

long long st2[100], dp[100];

long long len(long long a)
{
	long long ans;
	for(ans=0; a; ans++)
		a/=2;
	return ans;
}

vector<long long> find_div(long long a)
{
	vector<long long> ans;
	for(long long i=1; i*i<=a; i++)
		if (!(a%i))
		{
			ans.pb(i);
			if (a/i!=i)
				ans.pb(a/i);
		}
	return ans;
}

long long rec_sol(long long a, long long l0)
{
	long long l=len(a), q, tmp, tmp1, ans;
	if (l0!=l)
		return 0;
	if (!a)
		return 0;
	ans=a+1-(1<<(l-1));
	vector<long long> divs=find_div(l);
	for(int i=0; i<(int)divs.size(); i++)
	{
		if (divs[i]==l)
			continue;
		q=l/divs[i];
		tmp=a/st2[divs[i]*(q-1)];
		tmp1=0;
		for(int j=0; j<q; j++)
			tmp1=tmp1*st2[divs[i]]+tmp;
		if (tmp1<=a)
			ans-=rec_sol(tmp, divs[i]);
		else 
			ans-=rec_sol(tmp-1, divs[i]);
	}
	return ans;
}

long long solve(long long a)
{
	long long l=len(a), q, tmp, tmp1, ans;
	long long j, i, k;
	ans=0;
	vector<long long> divs=find_div(l);
	for(i=1; i<=l/2; i++)
	{
		ans+=((l-1)/i-1)*dp[i];
		if (!(l%i))
		{
			tmp=a/st2[l-i];
			q=l/i;
			tmp1=0;
			for(j=0; j<q; j++)
				tmp1=tmp1*st2[i]+tmp;
			if (tmp1<=a)
			{
				ans+=rec_sol(tmp, i);
			}
			else 
			{
				ans+=rec_sol(tmp-1, i);
			}
		}
	}
	return ans;
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	long long l, r, ansl, ansr;
	st2[0]=1;
	for(int i=1; i<70; i++)
		st2[i]=st2[i-1]*2;
	dp[1]=1;
	for(long long i=2; i<=70; i++)
	{
		vector<long long> divs=find_div(i);
		dp[i]=st2[i-1];
		for(int j=0; j<(int)divs.size(); j++)
			if (divs[j]!=i)
				dp[i]-=dp[divs[j]];
	}
	cin >> l >> r;
	ansl=solve(l-1);
	ansr=solve(r);
	cout << ansr-ansl;
}