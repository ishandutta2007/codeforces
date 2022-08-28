//CF 913B
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
int n,p[111111],s[111111],t[111111];
int main()
{
	int i,x;
	cin>>n;
	for(i=2;i<=n;i=i+1)
		cin>>p[i],s[p[i]]++;
	for(i=n;i>=1;i=i-1){
		if(!s[i])
			t[p[i]]++;
		else{
			if(t[i]<3){
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
	return 0;
}