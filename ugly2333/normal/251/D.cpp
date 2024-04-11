//CF 251D
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
const int Q = 61;
int n,ans[N],b[Q+5],c[Q+5];
LL a[N],w;
pair<LL,int> p[Q+5];
int main()
{
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i);
	for(j=0;j<=Q;j=j+1){
		w=(LL)1<<j;
		b[j]=1;
		p[j]=make_pair(w,j);
		l=0;
		for(i=1;i<=n;i=i+1)
			if(a[i]&w)
				l^=1;
		if(!l)
			p[j].first+=(LL)1<<Q;
	}
	sort(p,p+Q+1);
	for(l=Q;l>=0;l=l-1){
		j=p[l].second;
		//cout<<j<<' ';
		w=(LL)1<<j;
		for(i=1;i<=n;i=i+1)
			if(a[i]&w)
				break;
		if(i>n)
			continue;
		k=i;
		c[j]=k;
		a[k]^=w;
		for(i=1;i<=n;i=i+1)
			if(a[i]&w)
				a[i]^=a[k];
		for(i=0;i<=Q;i=i+1){
			w=(LL)1<<i;
			if(a[k]&w){
				a[k]^=w;
				b[i]^=b[j];
			}
		}
	}
	for(j=0;j<=Q;j=j+1)
		ans[c[j]]=b[j];
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]+1<<' ';
	cout<<endl;
	return 0;
}