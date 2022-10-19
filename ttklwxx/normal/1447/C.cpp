#include <bits/stdc++.h>
#define N 100001
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int t, n;
int a[N];
long long w,s,nice;
vector<int>ans;
int main()
{
	t=read();
	while (t--) {
		cin>>n>>w; 
		s=0;
		nice=0;
		for(int i=1; i<=n; i++)
		{
			int a;
			cin>>a;
			if(a>w)continue;
			else if(a<(w+1)/2)
			{
				if(s<(w+1)/2)ans.push_back(i),s+=a;
			}
			else nice = i;
		}
		if(nice)cout<<1<<endl<<nice<<endl;
		else if(s>=(w+1)/2)
		{
			cout<<ans.size()<<endl;
			for(int x : ans)cout<<x<<' ';
			cout<<endl;
		}
		else cout<<-1<<endl;
		ans.clear();
	}
}