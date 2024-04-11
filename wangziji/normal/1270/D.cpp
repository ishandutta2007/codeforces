#include <iostream>
using namespace std;
int a[100005];
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	cout << "? ";
	for(int i=1;i<=k;i++)
		cout << i << " ";
	cout << endl;
	int x1,y1;
	cin >> x1 >> y1;
	cout << "? ";
	for(int i=1;i<=k+1;i++)
	{
		if(i!=x1)
			cout << i << " ";
	}
	cout << endl;
	int x2,y2;
	cin >> x2 >> y2;
	int ans=0;
	for(int i=1;i<=k+1;i++)
	{
		if(i==x1||i==x2)
			continue;
		cout << "? ";
		for(int j=1;j<=k+1;j++)
		{
			if(j==x1||j==i)
				continue;
			cout << j << " ";
		}
		cout << x1 << endl;
		int x,y;
		cin >> x >> y;
		if(y1<y2&&y==y2)
			++ans;
		if(y1>y2&&y!=y2)
			++ans;
	}
	cout << "! " << ans+1 << endl;
	return 0;
}