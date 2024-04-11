//CF 903A
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
	int T,x;
	cin>>T;
	while(T--){
		cin>>x;
		if(x==1||x==4||x==2||x==5||x==8||x==11)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}