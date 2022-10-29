#include <bits/stdc++.h>
#define int long long
using namespace std;
int Test=0;
int Ans[10005],a[10005];
inline int query(int x,int y)
{
	cout << "and " << x << " " << y << endl;
	int a,b;
	if(!Test) cin >> a;
	cout << "or " << x << " " << y << endl;
	if(!Test) cin >> b;
	if(Test) return Ans[x]+Ans[y];
	return a+b;
}
signed main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	if(Test)
	{
		for(int i=1;i<=n;i++)
			cin >> Ans[i];
	}
	int ab=query(1,2),bc=query(2,3),ca=query(3,1),abc=ab+bc+ca;
	abc/=2;
	a[1]=abc-bc,a[2]=abc-ca,a[3]=abc-ab;
	for(int i=4;i<=n;i++)
		a[i]=query(1,i)-a[1];
	sort(a+1,a+n+1);
	cout << "finish " << a[k] << endl;
	return 0;
}