#include <iostream>
using namespace std;
int a[500005],b[500005],p[500005],ans[500005];
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> b[i];
		p[b[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		int x=p[a[i]];
		if(x<i) x+=n;
		++ans[x-i];
	}
	int Ans=0;
	for(int i=0;i<=n;i++)
		Ans=max(Ans,ans[i]);
	cout << Ans;
	return 0;
}