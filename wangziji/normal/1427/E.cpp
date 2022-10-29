#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
struct qaq
{
	int x;
	char op;
	int y;
};
vector <qaq> ans;
int b[100],s[1200005],cnt;
vector <int> qwq[100],ANS;
inline void ins(int x)
{
	vector <int> now,nxt;
	now.push_back(x);
	for(int i=62;i>=0;i--)
	{
		if(x&((int)1<<i))
		{
			if(!b[i])
			{
				b[i]=x;
				for(auto t:now) qwq[i].push_back(t);
				return ;
			}
			else
			{
				for(auto t:qwq[i])
					now.push_back(t);
				sort(now.begin(), now.end());
				nxt.clear();
				for(auto t:now)
				{
					if(nxt.empty()) nxt.push_back(t);
					else if(t==nxt.back()) nxt.pop_back();
					else nxt.push_back(t);
				}
				swap(now,nxt);
				x^=b[i];
			}
		}
	}
}
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	s[++cnt]=n;
	srand((unsigned long long)new char);
	for(int i=2;i<=1100000;i++)
	{
		char op='+';
		int x=1,y=cnt;
		s[++cnt]=s[x]+s[y];
	}
	for(int i=1;i<=cnt;i++)
	{
		ins(s[i]);
		if(b[0])
		{
			int qwqaq=qwq[0][0];
			int s=0;
			for(auto t:qwq[0]) s^=t;
		//	cout << s << "\n";
			for(auto t:qwq[0]) ANS.push_back(t);
			break;
		}
	}
	cnt=1;
	s[1]=n;
	for(int i=2;i<=100;i++)
	{
		char op='+';
		int x=cnt,y=cnt;
		s[i]=s[i-1]+s[i-1];
		if(s[i]>=1e17)
			break;
		ans.push_back({s[i-1],op,s[i-1]});
	}
	for(auto t:ANS)
	{
		cerr << t << "\n";
		int now=0;
		for(int i=0;i<62;i++)
		{
			if(t/n&((int)1<<i))
			{
				if(!now) now=((int)1<<i);
				else ans.push_back({((int)1<<i)*n,'+',now*n}),now+=(1<<i);
			}
		}
	}
	int qwq=0;
	for(int i=1;i<ANS.size();i++) ans.push_back({ANS[i],'^',qwq^=ANS[i-1]});
	cout << ans.size() << "\n";
	for(auto x:ans)
	{
		cout << x.x << " " << x.op << " " << x.y << "\n";
	}
	return 0;
}