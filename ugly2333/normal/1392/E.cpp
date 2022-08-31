//CF1392E
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
const int N = 33;
int n,q;
LL a[N][N],k,x;
void ad(int i,int j,LL u){
	if(j==1){
		a[i][j]+=u;
		return;
	}
	a[i][j]+=u;
	a[i][j-1]-=u;
	if(i==n)
		return;
	ad(i+1,j-1,u);
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(i!=1)
				ad(i,j,(LL)1<<(n+n-i-j));
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	cin>>q;
	while(q--){
		cin>>k;
		cout<<1<<' '<<1<<endl;
		x=(LL)1<<(n+n-3);
		for(i=1,j=1;x;x>>=1){
			if(k&x)
				i++;
			else
				j++;
			cout<<i<<' '<<j<<endl;
		}
	}
	return 0;
}