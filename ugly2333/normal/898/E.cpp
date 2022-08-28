//CF 898E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 222222;
int ss,sq[N];
int cost(int x){
	int r;
	r=lower_bound(sq,sq+ss,x)-sq;
	if(sq[r]==x)
		return 0;
	return min(sq[r]-x,x-sq[r-1]);
}
int s1,a1[N];
int s2,a2[N];
int t[N];
int main()
{
	int n,i,x;
	LL ans;
	for(i=0;i*i<=1e9+N;i=i+1)
		sq[ss++]=i*i;
	scanf("%d",&n);
	for(i=0;i<n;i=i+1){
		scanf("%d",&x);
		if(cost(x))
			a2[s2++]=x;
		else
			a1[s1++]=x;
	}
	ans=0;
	if(s1<=n/2){
		for(i=0;i<s2;i=i+1)
			t[i]=cost(a2[i]);
		sort(t,t+s2);
		for(i=0;s1<n/2;i=i+1)
			ans+=t[i],s1++;
	}
	else{
		sort(a1,a1+s1);
		for(i=s1-1;s2<n/2;i=i-1){
			ans++,s2++;
			if(!a1[i])
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}