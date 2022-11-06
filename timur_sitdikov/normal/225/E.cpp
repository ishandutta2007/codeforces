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
#define mp make_pair
#define point complex<double>

const long long mod=1000000007;

long long pow_mod(long long v, long long st)
{
	long long a=v, ans=1;
	for(; st; st/=2)
	{
		if (st&1)
			ans=(ans*a)%mod;
		a=(a*a)%mod;
	}
	return ans;
}

int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	long long n ,ans;
	long long m[40];
	m[0]=1;
	m[1]=2;
	m[2]=4;
	m[3]=6;
	m[4]=12;
	m[5]=16;
	m[6]=18;
	m[7]=30;
	m[8]=60;
	m[9]=88;
	m[10]=106;
	m[11]=126;
	m[12]=520;
	m[13]=606;
	m[14]=1278;
	m[15]=2202;
	m[16]=2280;
	m[17]=3216;
	m[18]=4252;
	m[19]=4422;
	m[20]=9688;
	m[21]=9940;
	m[22]=11212;
	m[23]=19936;
	m[24]=21700;
	m[25]=23208;
	m[26]=44496;
	m[27]=86242;
	m[28]=110502;
	m[29]=132048;
	m[30]=216090;
	m[31]=756838;
	m[32]=859432;
	m[33]=1257786;
	m[34]=1398268;
	m[35]=2976220;
	m[36]=3021376;
	m[37]=6972592;
	m[38]=13466916;
	m[39]=20996010;
	cin >> n;
	ans=pow_mod(2, m[n-1]);
	ans=(ans+mod-1)%mod;
	cout << ans;
}