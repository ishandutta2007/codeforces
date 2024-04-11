#include <iostream>
#define int long long
using namespace std;
pair <int,int> a,b,c;
inline void gao()
{
	if(a>b) swap(a,b);
	if(b>c) swap(c,b);
	if(a>b) swap(a,b);
//	cout << a.first << " " << b.first << " " << c.first << "\n";
	cout << c.first+c.first-b.first-a.first << endl;
	int x;
	cin >> x;
	if(!x) exit(0);
	if(x==a.second)
		cout << a.first+c.first+c.first-b.first-a.first-c.first << endl;
	else
		cout << b.first+c.first+c.first-b.first-a.first-c.first << endl;
}
signed main(int argc, char** argv) {
	cin >> a.first >> b.first >> c.first;
	a.second=1,b.second=2,c.second=3;
	cout << "First" << endl;
	if(a>b) swap(a,b);
	if(b>c) swap(c,b);
	if(a>b) swap(a,b);
	cout << 1 << endl;
	int x;
	cin >> x;
	if(!x) return 0;
	if(x==c.second) c.first++,gao();
	else if(x==b.second)
	{
	//	return 1;
		b.first++;
		cout << b.first-a.first << endl;
		int x;
		cin >> x;
		if(!x) return 0;
		c.first+=b.first-a.first,gao();
	}
	else if(x==a.second)
	{
	//	return 2;
		a.first++;
		cout << c.first-b.first << endl;
		int x;
		cin >> x;
		if(!x) return 0;
		c.first+=c.first-b.first,gao();
	}
	return 0;
}