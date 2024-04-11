//CF 963C
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
typedef double DB;
const int N = 222222;
const DB eps = 1e-15;
LL gcd(LL x,LL y){
	if(y)
		return gcd(y,x%y);
	else
		return x;
}
int n;
LL w[N],h[N],c[N];
map<LL,LL> W,H;
map<LL,LL>::iterator it;
int main()
{
	int i,ans=0;
	LL x=0,s=0;
	DB f,g;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%I64d%I64d%I64d",w+i,h+i,c+i);
		x=gcd(c[i],x);
	}
	for(i=1;i<=n;i=i+1){
		c[i]/=x;
		s+=c[i];
		W[w[i]]+=c[i];
		H[h[i]]+=c[i];
	}
	for(i=1;i<=n;i=i+1){
		f=(DB)W[w[i]]/s;
		g=(DB)c[i]/H[h[i]];
		if(-eps<f-g&&f-g<eps)
			;
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	for(i=1;(LL)i*i<=x;i=i+1){
		if((LL)x%i==0){
			ans+=2;
			if((LL)i*i==x)
				ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}