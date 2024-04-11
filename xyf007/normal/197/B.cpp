#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,maxn=0,nn,mm,maxm=0,a[110],b[110];
	cin>>n>>m;
	for(int i=1;i<=n+1;i++)
	{
		cin>>a[i];
	}
	nn=a[1];
	for(int i=1;i<=m+1;i++)
	{
		cin>>b[i];
	}
	mm=b[1];
	if(n<m) printf("0/1");
	if(n>m) {
		if(nn>0 && mm>0 || nn<0 && mm<0) printf("Infinity");
		if(nn<0 && mm>0 || nn>0 && mm<0) printf("-Infinity");
	}
	if(n==m) {
		int nnn=abs(nn), mmm=abs(mm);
		for(int i=2;i<=min(mmm,nnn);i++)
		{
			while(nnn%i==0 && mmm%i==0){
				nnn/=i;
				mmm/=i;
			}
		}
		if(nn<0 && mm>0 || nn>0 && mm<0) printf("-");
		cout<<nnn<<'/'<<mmm;
	}
	return 0;
}