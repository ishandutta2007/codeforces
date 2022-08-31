//CF1090L
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
int main()
{
	LL t,n,a,b,k,s,w;
	cin>>t>>n>>a>>b>>k;
	if(n<k){
		cout<<0;
		return 0;
	}
	s=((n+1)/2)*a;
	w=(n/2)*b;
	t=min(t,(s+w)/k);
	if(k>(n/2))
		t=min(t,s/(k-n/2));
	if(k>(n+1)/2)
		t=min(t,w/(k-(n+1)/2));
	cout<<t;
	return 0;
}