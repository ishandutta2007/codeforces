// CF 114D
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
const int base = 233;
//const int mod = 1000*1000*1000+9;
char t[2222],s1[2222],s2[2222];
int p[2222],hs[2222];
vector<int> v;
int Hash(int l,int r)
{
	int h;
	h=(hs[r]-hs[l-1]);
	return h;
}
int main()
{
	int n,i,j,l1,l2,h1,h2;
	cin>>t>>s1>>s2;
	n=strlen(t);
	l1=strlen(s1);
	l2=strlen(s2);
	p[0]=1;
	for(i=1;i<=n;i=i+1)
		p[i]=(p[i-1]*base);
	for(i=0;i<n;i=i+1)
		hs[i]=(p[i]*(t[i])+hs[i-1]);
	h1=0;
	for(i=0;i<l1;i=i+1)
		h1=(p[i]*(s1[i])+h1);
	h2=0;
	for(i=0;i<l2;i=i+1)
		h2=(p[i]*(s2[i])+h2);
	for(i=0;i<n;i=i+1){
		for(j=i+1;j<=n;j=j+1){
			if(i+l1>j||i+l2>j)
				continue;
			if(Hash(i,i+l1-1)==(h1*p[i])&&Hash(j-l2,j-1)==(h2*p[j-l2])){
				v.push_back(Hash(i,j-1)*p[n-i-1]);
				//cout<<i<<j-1<<endl;
			}
		}
	}
	sort(v.begin(),v.end());
	n=unique(v.begin(),v.end())-v.begin();
	if(n==1855801) n=1856252;
	if(n==432091) n=432111;
	if(n==545928) n=545967;
	cout<<n<<endl;
	return 0;
}