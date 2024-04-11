#include <iostream>
using namespace std;
string t[5005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string a;
		cin >> a;
		string b,ans="";
		ans+=char('z'+1);
		int w=0;
		for(int i=1;i<=n;i++)
		{
	//		b=a;
	//		for(int j=0;j<n-i+1;j++)
	//		{
	//			int x=j,y=j+i-1;
	//			while(x<y) swap(b[x],b[y]),++x,--y;
	//		}
	//		cout << b << " ";
			string s=a.substr(0,i-1);
			int x=0,y=s.size()-1;
			if(!((i-(int)a.size())&1))
			while(x<y) swap(s[x],s[y]),++x,--y;
			t[i]=a.substr(i-1)+s;
			if(t[i]<ans) ans=t[i],w=i;
	//		cout << t[i] << "\n";
		}
		cout << ans << "\n" << w << "\n";
		/*if(n&1)
			for(int i=0;i<n/2;i++) swap(a[i],a[n-i-1]);
		a+=a;
		string ans="";
		ans+=char('z'+1);
		for(int i=0;i<n;i++)
		{
			ans=min(ans,a.substr(i,n));
		}
		cout << ans << "\n";*/
	}
	return 0;
}