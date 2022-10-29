#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	string a;
	cin >> n >> a;
	a=' '+a;
	int now=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(')++cnt;
		else --cnt;
	}
	if(cnt)
	{
		puts("-1");
		return 0;
	}
	int ans=0,lst=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(') ++cnt;
		else --cnt;
	//	cout << cnt << " ";
		if(cnt<0||lst<0) ++ans;
		lst=cnt;
	}
	//cout << endl;
	cout << ans;
	return 0;
}