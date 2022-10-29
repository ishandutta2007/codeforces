#include <iostream>
#include <vector>
#define int long long
using namespace std;
vector <int> v;
signed main(int argc, char** argv) {
	int n,m,k;
	cin >> n >> m >> k;
	if(n*m*2%k!=0)
	{
		puts("NO");
		return 0;
	}
	int t=n*m*2/k;
	for(int i=1;i<=30000000;i++)
	{
		if(i>t/i) break;
		if(t%i==0&&(t/i<=max(n,m)&&i<=min(n,m)))
		{
			puts("YES");
			puts("0 0");
				if(n>m)
				{
					cout << t/i << " 0" << endl;
					cout << "0 " << i << endl;
					return 0;
				}
				else
				{
					cout << "0 " << t/i << endl;
					cout << i << " 0" << endl;
					return 0;
				}
		}
	}
	for(int i=1;i<=30000000;i++)
	{
		if(n%i==0)
			v.push_back(i);
	}
	for(int i=1;i<=30000000;i++)
	{
		if(m%i==0)
			v.push_back(i);
	}
	for(int i=m;i>=max(m-10000000,(int)1);i--)
		if(m%i==0)
			v.push_back(i);
			
	for(int i=n;i>=max(n-10000000,(int)1);i--)
		if(n%i==0)
			v.push_back(i);
	int S=v.size();
	for(int i=0;i<S;i++)
	{
		for(int j=i+1;j<S;j++)
		{
			int x=v[i]*v[j];
			if(x>t/x) x=t/x;
			#define i x
			if(t%i==0&&(t/i<=max(n,m)&&i<=min(n,m)))
			{
				puts("YES");
				puts("0 0");
				if(n>m)
				{
					cout << t/i << " 0" << endl;
					cout << "0 " << i << endl;
					return 0;
				}
				else
				{
					cout << "0 " << t/i << endl;
					cout << i << " 0" << endl;
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}