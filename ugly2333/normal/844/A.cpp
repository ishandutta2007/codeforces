//CF 844A
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
int s[33],k,h;
int main()
{
	char cc[1111];
	cin>>cc>>k;
	int n,i;
	n=strlen(cc);
	if(n<k){
		cout<<"impossible\n";
		return 0;
	}
	for(i=0;i<n;i=i+1)
		s[cc[i]-'a'+1]++;
	for(i=1;i<=26;i=i+1)
		h+=(s[i]>0);
	if(h>k)
		h=k;
	cout<<k-h<<endl;
	return 0;
}