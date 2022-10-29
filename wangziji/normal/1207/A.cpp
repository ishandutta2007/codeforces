#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int a,b,c,d,e,f,ans=0;
		cin >>a  >>b  >> c >> d >> e;
		a/=2;
		if(d>e) ans+=min(a,b)*d,f=min(a,b),a-=f,b-=f;
		ans+=min(a,c)*e,f=min(a,c),a-=f,c-=f;
		ans+=min(a,b)*d,f=min(a,b)*d,a-=f,b-=f;
		cout << ans << endl;
	}
	return 0;
}