#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<math.h>
#include<map>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

int T1[100005], T2[100005];
LL res1, res2, sum1, sum2;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {scanf("%d", T1+i); sum1+=(LL)T1[i];}
	for(int i=0; i<m; i++) {scanf("%d", T2+i); sum2+=(LL)T2[i];}
	sort(T1, T1+n);
	sort(T2, T2+m);
	res2+=sum2;
	res1+=sum1;
	for(int i=n-2; i>=0; i--) res2+=min((LL)T1[i], sum2);
	for(int i=m-2; i>=0; i--) res1+=min((LL)T2[i], sum1);
	cout<< min(res1, res2) << "\n";
	return 0;
}