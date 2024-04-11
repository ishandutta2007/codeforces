//CF 896B
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
const int N = 1111;
int n,m,c,c2,a[N];
bool chk(){
	int i;
	for(i=1;i<=n;i=i+1)
		if(!a[i])
			return 0;
	for(i=2;i<=n;i=i+1)
		if(a[i-1]>a[i])
			return 0;
	return 1;
}
int main()
{
	int i,x;
	cin>>n>>m>>c;
	c2=(c+1)/2;
	while(m--){
		cin>>x;
		if(x>c2){
			i=n;
			while(a[i]&&a[i]>=x){
				i--;
			}
			a[i]=x;
			cout<<i<<endl;
		}
		else{
			i=1;
			while(a[i]&&a[i]<=x){
				i++;
			}
			a[i]=x;
			cout<<i<<endl;
		}
		if(chk())
			return 0;
	}
	return 0;
}