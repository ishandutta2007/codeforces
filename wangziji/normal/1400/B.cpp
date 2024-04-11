#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d,e,f;
		cin >> a >> b >> c >> d >> e >> f;
		if(e>f) swap(e,f),swap(c,d);
		int ans=0;
		for(int i=0;i<=c;i++)
		{
			if(i*e>a) break;
			int X=min((a-i*e)/f,d);
			int t=i+X;
			int x=min(c-i,b/e);
			t+=x+min((b-x*e)/f,d-X);
			ans=max(ans,t);
		}
		cout << ans << "\n";
	}
	return 0;
}