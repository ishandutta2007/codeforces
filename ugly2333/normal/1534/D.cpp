//CF1534D
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
const int N = 2222;
int n,d[N],e[N],f[2],a[N][N];
void q(int x){
	int i;
	cout<<'?'<<' '<<x<<endl;
	for(i=1;i<=n;i++)
		scanf("%d",d+i);
}

int main()
{
	int i,j,x;
	cin>>n;
	q(1);
	for(i=1;i<=n;i++)
		e[i]=d[i];
	for(i=2;i<=n;i++)
		f[d[i]%2]++;
	if(f[0]<f[1])
		x=0;
	else
		x=1;
	if(x==0){
		for(i=1;i<=n;i++)
			if(d[i]==1)
				a[1][i]=1;
	}
	for(i=2;i<=n;i++){
		if(e[i]%2==x){
			q(i);
			for(j=1;j<=n;j++)
				if(d[j]==1)
					a[i][j]=1;
		}
	}
	cout<<'!'<<endl;
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			if(a[i][j]||a[j][i])
				cout<<i<<' '<<j<<endl;
	return 0;
}