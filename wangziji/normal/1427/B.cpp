#include <iostream>
#include <algorithm> 
using namespace std;
int a[200005],cnt;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		string s;
		cin >> n >> k >> s;
		cnt=0;
		int lst=-2;
		int w=0,qwq=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='W')
			{
				++w;
				if(lst!=-2&&lst!=i-1) a[++cnt]=i-lst-1;
				if(lst==i-1) ++qwq;
				lst=i;
			}
		}
		if(k+w>=n)
		{
			cout << n*2-1 << "\n";
			continue;
		}
		if(!w)
		{
			cout << max(k*2-1,0) << "\n";
			continue;
		}
		sort(a+1,a+cnt+1);
		int ans=0;
//		cout << w+qwq << "\n";
		for(int i=1;i<=cnt;i++)
		{
			if(k>=a[i])
				ans+=1+a[i]*2,k-=a[i];
			else
			{
				break;
			}
		}
		cout << ans+k*2+w+qwq << "\n";
	}
	return 0;
}