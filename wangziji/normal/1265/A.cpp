#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		string ans="";
		cin >> a;
		int n=a.size();
		a=" "+a;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i+1]&&a[i]!='?')
			{
				puts("-1"),ans="";
				break;
			}
			if(a[i]=='?')
			{
				if(a[i-1]!='a'&&a[i+1]!='a')
					ans+='a';
				else if(a[i-1]!='b'&&a[i+1]!='b')
					ans+='b';
				else if(a[i-1]!='c'&&a[i+1]!='c')
					ans+='c';
				a[i]=ans[ans.size()-1];
			}
			else
				ans+=a[i];
		}
		if(ans.size()==n)
			cout << ans<< endl;
	}
	return 0;
}