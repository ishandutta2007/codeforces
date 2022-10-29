#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[20005],b[20005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,ans=0;
		memset(b,0,sizeof b);
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int t;
			cin >> t;
			if(!b[t]) a[i]=t;
			else a[i]=t+10000,++ans;
			b[t]=1;
		}
		cout << ans << endl;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<10000)
				printf("%04d\n",a[i]);
			else
			{
				int A,B,C,D,X;
				A=a[i]/1000%10;
				B=a[i]/100%10;
				C=a[i]/10%10;
				D=a[i]%10;
				int flag=0;
				for(int i=0;i<=9;i++)
				{
					if(!b[X=i*1000+B*100+C*10+D])
					{
						printf("%04d\n",X);
						b[X]=1;
						flag=1;
						break;
					}
				}
				if(flag) continue;
				for(int i=0;i<=9;i++)
				{
					if(!b[a[i]=A*1000+i*100+C*10+D])
					{
						printf("%04d\n",X);
						b[X]=1;
						flag=1;
						break;
					}
				}
				if(flag) continue;
			}
		}
	}
	return 0;
}