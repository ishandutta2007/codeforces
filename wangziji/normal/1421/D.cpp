#include <iostream>
#define int long long
using namespace std;
int a[10];
int fx[10]={0,1,0,-1,-1,0,1};
int fy[10]={0,1,1,0,-1,-1,0};
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int x,y;
		cin >> x >> y;
		for(int i=1;i<=6;i++) cin >> a[i];
		for(int i=1;i<=100;i++)
		{
			for(int j=1;j<=6;j++)
				if(a[i]>a[i%6+1]+a[i-1+6*(i==1)])
					a[i]=a[i%6+1]+a[i-1+6*(i==1)];
		}
		long long ans=5e18;
		for(int i=1;i<=6;i++)
		{
			for(int j=i+1;j<=6;j++)
			{
				if(fx[i]+fx[j]==0&&fy[i]+fy[j]==0)
					continue;
				int A=0,B=0;
				if(i%3!=1&&j%3!=1)
				{
			//		cout << i << " " << j << " " << A << " " << B << "\n"; 
					if(fx[i]) A=x/fx[i],B=y/fy[j];
					else A=y/fy[i],B=x/fx[j];
				if(A>=0&&B>=0) ans=min(ans,A*a[i]+B*a[j]);
					continue;
				}
				int flag=0;
				if(j%3==1) swap(i,j),flag=1;
				if(fy[j]) A=x/fx[i],B=(y-A*fy[i])/fy[j];
				else A=y/fy[i],B=(x-A*fx[i])/fx[j];
			//		cout << i << " " << j << " " << A << " " << B << "\n";
				if(A>=0&&B>=0) ans=min(ans,A*a[i]+B*a[j]);
				if(flag) swap(i,j);
				if(A<0||B<0) continue;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}