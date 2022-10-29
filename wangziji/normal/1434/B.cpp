#include <iostream>
#include <set>
using namespace std;
char op[200005];
int s[200005],cnt,w[200005];
set <int> S;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n+n;i++)
	{
		cin>> op[i];
		if(op[i]=='-')
		{
			cin >> w[i];
			if(!cnt)
			{
				puts("NO");
				return 0;
			}
			w[s[cnt--]]=w[i];
		}
		else s[++cnt]=i;
	}
	for(int i=1;i<=n+n;i++)
	{
		if(op[i]=='-')
		{
			if(*S.begin()!=w[i])
			{
				puts("NO");
				return 0;
			}
			S.erase(S.begin());
		}
		else S.insert(w[i]);
	}
	puts("YES");
	for(int i=1;i<=n+n;i++)
	{
		if(op[i]=='+')
			cout << w[i] << " ";
	}
	return 0;
}