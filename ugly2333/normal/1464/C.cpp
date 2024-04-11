//CF1465C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const int M = 66;
int n,a[N],m=60,c[M];
LL k;
char s[N];
int main()
{
	int i,x;
	cin>>n>>k>>s;
	for(i=0;i<n;i=i+1)
		a[i]=s[i]-'a';
	k-=1<<a[n-1];
	k+=1<<a[n-2];
	for(i=0;i<n-2;i=i+1){
		k+=1<<a[i];
		c[a[i]+1]++;
	}
	for(i=0;i<=m;i=i+1){
		if(c[i]>2){
			x=(c[i]-1)/2;
			c[i+1]+=x;
			c[i]-=x*2;
		}
	}
	for(i=m;i>=0;i=i-1){
		while(c[i]&&k>=((LL)1<<i)){
			k-=(LL)1<<i;
			c[i]--;
		}
	}
	if(k==0)
		printf("Yes");
	else
		printf("No");
	return 0;
}