#include <iostream>
using namespace std;
int a[10],b[10],ans[200005],cnt;
int main(int argc, char** argv) {
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	for(int i=0;i<=3;i++)
	{
		if(!a[i]) continue;
		for(int j=0;j<=3;j++) b[j]=a[j];
		int now=i;
		ans[cnt=1]=now,--b[now];
		while(1)
		{
			if(now&&b[now-1])
				--b[--now],ans[++cnt]=now;
			else if(3^now&&b[now+1])
				--b[++now],ans[++cnt]=now;
			else break;
		}
		if(cnt==a[0]+a[1]+a[2]+a[3])
		{
			puts("YES");
			for(int j=1;j<=cnt;j++)
				cout << ans[j] << " ";
			return 0;
		}
	}
	puts("NO"); 
	return 0;
}