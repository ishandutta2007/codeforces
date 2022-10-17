#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=200005,maxk=27;
int n,m,ans;
int f[maxn],L[maxn],R[maxn];
string s,t;
int main(){
	scanf("%d%d",&n,&m);
	cin>>s>>t;
	for(int i=0,j=0;i<n;i++)
		if(j<m&&s[i]==t[j])
			L[j]=i,j++;
	for(int i=n-1,j=m-1;i>=0;i--)
		if(j>=0&&s[i]==t[j])
			R[j]=i,j--;
	for(int i=1;i<m;i++)
		ans=max(ans,R[i]-L[i-1]);
	printf("%d\n",ans);
	return 0;
}