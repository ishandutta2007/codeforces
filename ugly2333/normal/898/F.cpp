//CF 898F
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
const int N = 1111111;
const int mod = 998244353;
char ch[N];
int n,a[N],b[N];
LL pw[N],h[N];
LL gethash(int l,int r){
	return (h[r]-h[l-1]*pw[r-l+1]%mod+mod)%mod;
}
void prt(int i,int j){
	int o;
	for(o=1;o<=i;o=o+1)
		cout<<ch[o];
	cout<<'+';
	for(o=i+1;o<=j;o=o+1)
		cout<<ch[o];
	cout<<'=';
	for(o=j+1;o<=n;o=o+1)
		cout<<ch[o];
	cout<<endl;
	exit(0);
}
void cal(int i,int j){
	int o;
	memset(b,0,sizeof(b));
	for(o=1;o<=i;o=o+1)
		b[i-o]+=a[o];
	for(o=i+1;o<=j;o=o+1)
		b[j-o]+=a[o];
	for(o=0;o<=i||o<=j-i;o=o+1)
		if(b[o]>=10)
			b[o+1]++,b[o]-=10;
	for(o=j+1;o<=n;o=o+1)
		b[n-o]-=a[o];
	for(o=0;o<=n;o=o+1)
		if(b[o])
			return;
	prt(i,j);
}
void chk(int i,int j){
	if(i<=0||i>=n||i>=j||j<=0||j>=n)
		return;
	if(a[1]==0&&i>1)
		return;
	if(a[i+1]==0&&j>i+1)
		return;
	if(a[j+1]==0&&n>j+1)
		return;
	if((gethash(1,i)+gethash(i+1,j))%mod==gethash(j+1,n))
		cal(i,j);
}
int main()
{
	int i,j;
	pw[0]=1;
	for(i=1;i<N;i=i+1)
		pw[i]=pw[i-1]*10%mod;
	scanf("%s",ch+1);
	ch[0]='_';
	n=strlen(ch)-1;
	h[0]=0;
	for(i=1;i<=n;i=i+1){
		a[i]=ch[i]-'0';
		h[i]=(h[i-1]*10+a[i])%mod;
	}
	for(i=2;i<n;i=i+1){
		j=n-i;
		chk(j,i),chk(j-1,i);
		chk(i-j,i),chk(i-j+1,i);
	}
	return 0;
}