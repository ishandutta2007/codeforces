//CF1637G
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
const int N = 1<<20;
int n,m,a[N];
vector<int> ans[2];
void go(int x,int y){
	ans[0].push_back(x);
	ans[1].push_back(y);
	a[x]--;
	a[y]--;
	if(a[x]<0||a[y]<0){
		cout<<1/0;
	}
	a[x+y]++;
	a[abs(x-y)]++;
}
void solve(int n,int k){
	if(n<=2)
		return;
	int l,x,i;
	x=n;
	while(x%2==0){
		x/=2;
	}
	if(x==1)
		n--;
	for(l=2;l<=n;l<<=1);
	l>>=1;
	for(i=n;i>l;i--)
		go(i<<k,(l*2-i)<<k);
	solve(l*2-n-1,k);
	solve(n-l,k+1);
}
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==2)
			printf("-1\n");
		else{
			for(m=1;m<n;m<<=1);
			ans[0].clear();
			ans[1].clear();
			for(i=1;i<=n;i++)
				a[i]=1;
			solve(n,0);
			if(n==5)
				go(2,2);
			else
				go(m/2,m/2);
			for(i=1;i<m;i<<=1){
				while(a[i]){
					go(0,i);
					go(i,i);
				}
			}
			go(0,m);
			if(a[m]!=n){
				cout<<1/0;
			}
			a[m]=0;
			printf("%d\n",ans[0].size());
			for(i=0;i<ans[0].size();i++)
				printf("%d %d\n",ans[0][i],ans[1][i]);
		}
	}
	return 0;
}