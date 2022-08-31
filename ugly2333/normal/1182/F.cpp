//CF1182F
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
const int M = 33333;
int a,b,p,q,r,s,m;
pair<int,int> f[N];
void go(int c){
	int d=(LL)c*p%q;
	if(d>q-d)
		d=q-d;
	if(d>s||(d==s&&c<r))
		r=c,s=d;
}
int main()
{
	int t,i,c,d,k;
	cin>>t;
	while(t--){
		cin>>a>>b>>p>>q;
		k=q/2;
		r=-1,s=-1;
		while(a<=b&&a%M){
			go(a);
			a++;
		}
		while(a<=b&&b%M!=M-1){
			go(b);
			b--;
		}
		if(a>b){
			cout<<r<<endl;
			continue;
		}
		a/=M,b/=M;
		for(i=0;i<M;i=i+1)
			f[i]=make_pair(((LL)i*p+k)%q,i);
		sort(f,f+M);
		for(i=M-1;i>=1;i=i-1)
			if(f[i].first==f[i-1].first)
				f[i]=make_pair(-1,-1);
		m=0;
		for(i=0;i<M;i=i+1)
			if(f[i].second>=0)
				f[m++]=f[i];
		while(a<=b){
			c=a*M;
			d=(LL)c*p%q;
			go(c+f[0].second);
			go(c+f[m-1].second);
			i=lower_bound(f,f+m,make_pair(q-d,-1))-f;
			if(i<m)
				go(c+f[i].second);
			i--;
			if(i>=0)
				go(c+f[i].second);
			a++;
		}
		cout<<r<<endl;
	}
	return 0;
}