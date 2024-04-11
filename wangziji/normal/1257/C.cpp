#include <iostream>
using namespace std;
int lst[200005],a[200005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			lst[i]=0;
		int ans=123456789;
		for(int i=1;i<=n;i++)
		{
			if(lst[a[i]])
				ans=min(ans,i-lst[a[i]]+1);
			lst[a[i]]=i;
		}
		if(ans>n)
			ans=-1;
		cout << ans << endl;
	}
	return 0;
}