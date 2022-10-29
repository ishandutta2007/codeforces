#include <iostream>
using namespace std;
int a[200005],t[200005],b[200005];
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int q;
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		int op;
		cin >> op;
		if(op==2)
			cin >> b[i];
		else
		{
			int x,y;
			cin >> x >> y;
			a[x]=y;
			t[x]=i;
		}
	}
	for(int i=q-1;i>=0;i--)
		b[i]=max(b[i],b[i+1]);
	for(int i=1;i<=n;i++)
	{
		a[i]=max(a[i],b[t[i]]);
		cout << a[i] << " ";
	}
	return 0;
}