#include <iostream>
#define int long long
using namespace std;
int a[300005],b[300005],qzh[300005];
inline int cnt(int x)
{
	int rtn=0;
	while(x)
	{
		rtn+=x&1;
		x>>=1;
	}
	return rtn;
}
signed main(int argc, char** argv) {
	int n,ans=0,x=0,y=0,nowx=0,nowy=0;//xy 
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=cnt(a[i]);
		qzh[i]=qzh[i-1]+b[i];
		if(b[i]&1)
		{
			swap(nowx,nowy);
			++nowy;
			x+=nowx,y+=nowy;
		}
		else
			x+=++nowx,y+=nowy;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=min((int)200,n-i+1);j++)
		{
			mx=max(mx,b[i+j-1]);
			if(qzh[j+i-1]-qzh[i-1]<mx*2&&(qzh[j+i-1]-qzh[i-1])%2==0)
				++ans;
			++cnt;
		}
	}
	/*
	for(int i=1;i<=100;i++)
	{
		int mx=0;
		for(int j=1;j<=n-i+1;j++)
		{
			mx=max(mx,)
			if(qzh[j+i-1]-qzh[j-1]<mx&&(qzh[j+i-1]-qzh[j-1])%2==0)
				--ans;
		}
	}*/
	cout << x-ans << endl;
	return 0;
}