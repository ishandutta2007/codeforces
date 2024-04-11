#include <iostream>
using namespace std;
string s;
char ans[105];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int a,b,c;
		int x,y,z;
		z=y=x=0;
		cin >> a >> b >> c;
		s=" ";
		for(int i=1;i<=n;i++)
		{
			char t;
			cin >> t;
			s+=t;
			if(t=='R')
				++x;
			if(t=='P')
				++y;
			if(t=='S')
				++z;
		}
		for(int i=1;i<=101;i++)
			ans[i]=' ';
		if(min(a,z)+min(b,x)+min(c,y)>=(n+1)/2)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='S'&&a)
					--a,ans[i]='R';
				if(s[i]=='R'&&b)
					--b,ans[i]='P';
				if(s[i]=='P'&&c)
					--c,ans[i]='S';
			}
			for(int i=1;i<=n;i++)
			{
				if(ans[i]!='P'&&ans[i]!='R'&&ans[i]!='S')
				{
					if(a) --a,ans[i]='R';else 
					if(b) --b,ans[i]='P';else 
					if(c) --c,ans[i]='S';
				}
			}
			for(int i=1;i<=n;i++)
				cout << ans[i];
			cout << endl;
		}
		else
			puts("NO");
	}
	return 0;
}