#include<bits/stdc++.h>
using namespace std;
#define N 300010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define MOD 998244353

int n,m,t,x,y;
int a[N],b[N],num[N],num0[N];
bool flag;
vector<int> g[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	scanf("%d",&n);
	if(n==3){
		cout<<"1 2 3"<<endl;
		return 0;
	}
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
	int x = 1;
	rep(i,1,n){
		printf("%d ",x);
		int y=a[x], z=b[x];
		x = (a[y]==z||b[y]==z)?y:z;
	}
	printf("\n");
	return 0;
}