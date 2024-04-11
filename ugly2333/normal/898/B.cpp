//CF 898B
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
int main()
{
	int n,a,b,x;
	cin>>n>>a>>b;
	for(x=0;x*a<=n;x=x+1){
		if((n-a*x)%b==0){
			cout<<"YES\n"<<x<<' '<<(n-x*a)/b<<endl;
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}