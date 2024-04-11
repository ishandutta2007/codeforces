//CF 873B
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
const int N = 111111;
char ch[N];
int l[N*4],r[N*4];
int main()
{
	int n,i,s0,s1,ans;
	cin>>n>>ch;
	s0=0,s1=0;
	l[N+N]=1;
	for(i=0;i<n;i=i+1){
		if(ch[i]=='1')
			s1++;
		else
			s0++;
		if(!l[N+N+s1-s0])
			l[N+N+s1-s0]=i+2;
	}
	s0=0,s1=0;
	r[N+N]=n+2;
	for(i=n-1;i>=0;i=i-1){
		if(ch[i]=='1')
			s1++;
		else
			s0++;
		if(!r[N+N+s1-s0])
			r[N+N+s1-s0]=i+2;
	}
	ans=0;
	for(i=-N-N+111;i<=N+N-111;i=i+1){
		if(l[N+N+i]&&r[N+N+s1-s0-i])
			ans=max(ans,r[N+N+s1-s0-i]-l[N+N+i]-1);
	}
	cout<<ans<<endl;
	return 0;
}
// 10 1010101010
// 10