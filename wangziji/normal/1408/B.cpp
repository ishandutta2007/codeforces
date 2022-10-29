#include <iostream>
#include <cstring>
using namespace std;
int a[105],cnt[105];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		int qwq=0,qaq=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			++cnt[a[i]];
			qwq+=cnt[a[i]]==1&&a[i];
			qaq+=cnt[a[i]]==1;
		}
		if(k==1&&qaq>1)
		{
			puts("-1");
		}
		else if(k==1) puts("1");
		else if(qaq==1) puts("1");
		else cout << (qaq-2)/(k-1)+1 << "\n";
	}
	return 0;
}