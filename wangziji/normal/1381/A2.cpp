#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;
int qwq[100005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		ans.clear();
		int n;
		cin >> n;
		string a,b;
		cin >> a >> b;
		a=' '+a,b=' '+b;
		int x=1,y=n,cnt=0;
		while(x<y)
			qwq[++cnt]=x++,qwq[++cnt]=y--;
		qwq[++cnt]=x++,qwq[++cnt]=y--;
		int flag=0;
		for(int i=n;i>=1;i--)
		{
			if(b[i]==a[qwq[n-i+1]]&&!flag||b[i]!=a[qwq[n-i+1]]&&flag) ans.push_back(1);
			flag^=1;
			ans.push_back(i);
		}
		cout << ans.size() << " ";
		for(auto x:ans) cout << x << " ";
		puts("");
	}
	return 0;
}