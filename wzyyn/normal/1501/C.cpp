#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second 
#define PB push_back
using namespace std;

const int N=5000005;
int n,a[N];
vector<int> v[N];
pii vi[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) v[a[i]].PB(i);
	int la=-1;
	For(i,0,N-1) if (v[i].size()>=2){
		if (la==-1) la=i;
		else{
			printf("YES\n%d %d %d %d",v[i][0],v[la][0],v[i][1],v[la][1]);
			return 0;
		}
	}
	For(i,1,n) For(j,i+1,n)
		if (vi[a[i]+a[j]].fi==0)
			vi[a[i]+a[j]]=pii(i,j);
		else
			if (i!=vi[a[i]+a[j]].fi&&i!=vi[a[i]+a[j]].se)
				if (j!=vi[a[i]+a[j]].fi&&j!=vi[a[i]+a[j]].se){
					printf("YES\n%d %d %d %d\n",i,j,vi[a[i]+a[j]].fi,vi[a[i]+a[j]].se);
					return 0;
				}
	puts("NO");
}