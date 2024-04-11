#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, T[105];
string s;
char C[]={'a', 'e', 'i', 'o', 'u', 'y'};

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<n; i++)
		cin>> T[i];
	getline(cin, s);
	for(int i=0; i<n; i++)
	{
		getline(cin, s);
		//cout<< s << '\n';
		int siz=s.size();
		for(int j=0; j<siz; j++)
		{
			bool boo=0;
			for(int k=0; k<6; k++)
				if(s[j]==C[k])
					boo=1;
			if(boo)
				T[i]--;
		}
		if(T[i]!=0)
		{
			cout<< "NO\n";
			return 0;
		}
	}
	cout<< "YES\n";
	return 0;
}