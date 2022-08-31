//CF 963D
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
const int N = 111111;
const int B = 131;
const int mod = 998244353;
int n,q,k[N],a[N],r[N];
vector<int> v[N];
vector<pair<int,int> > h[N];
LL p[N];
char s[N],c[N];
queue<int> Q[N];
int lb(int i,LL z){
	int L=0,R=r[i]-1,t;
	while(L<=R){
		t=(L+R)>>1;
		if(v[i][t]==z)
			return t;
		if(v[i][t]<z)
			L=t+1;
		else
			R=t-1;
	}
	return -1;
}
int main()
{
	int i,j,l;
	LL x;
	scanf("%s",s+1);
	n=strlen(s+1);
	p[0]=1;
	for(i=1;i<=n;i=i+1)
		p[i]=p[i-1]*B%mod;
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%s",k+i,c+1);
		k[i]--;
		l=strlen(c+1);
		r[l]++;
		x=0;
		for(j=1;j<=l;j=j+1)
			x=((LL)x*B+c[j])%mod;
		h[l].push_back(make_pair(x,i));
		a[i]=n+1;
	}
	for(l=1;l<=n;l=l+1){
		if(!r[l])
			continue;
		sort(h[l].begin(),h[l].end());
		for(i=0;i<r[l];i=i+1)
			v[l].push_back(h[l][i].first);
		x=0;
		for(i=1;i<l;i=i+1)
			x=((LL)x*B+s[i])%mod;
		for(i=l;i<=n;i=i+1){
			x=((LL)x*B+s[i])%mod;
			x=((LL)x-p[l]*s[i-l]%mod+mod)%mod;
			j=lb(l,x);
			if(j>=0){
				j=h[l][j].second;
				Q[j].push(i);
				if(k[j])
					k[j]--;
				else{
					a[j]=min(a[j],i-Q[j].front()+l);
					Q[j].pop();
				}
			}
		}
	}
	for(i=1;i<=q;i=i+1){
		if(a[i]>n)
			a[i]=-1;
		printf("%d\n",a[i]);
	}
	return 0;
}