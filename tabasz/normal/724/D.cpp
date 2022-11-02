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

int m, st, l, siz, T[26], R[26], maxi;
string s;
vector<int> V;

void add(int ind)
{
	while((int)V.size()>st && s[V[V.size()-1]]>=s[ind])
		V.pb();
	V.PB(ind);
}

void remove(int ind)
{
	if(V[st]==ind)
		st++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> m >> s;
	siz=s.size();
	for(int i=0; i<siz; i++)
		T[(int)s[i]-(int)'a']++;
	for(int i=0; i<m; i++)
		add(i);
	int last=m-1;
	while(true)
	{
		int ind=V[st];
	//	printf("%d: %c\n", last, s[ind]);
		R[(int)s[ind]-(int)'a']++;
		maxi=max(maxi, (int)s[ind]-(int)'a');
		if(ind+m>=siz)
			break;
		while(last<=ind+m && last<siz)
		{
			add(last);
			last++;
		}
		remove(ind);
	}
	for(int i=0; i<26; i++)
	{
		if(i!=maxi)
			for(int j=0; j<T[i]; j++)
				cout<< (char)(i+(int)'a');
		else
		{
			for(int j=0; j<R[i]; j++)
				cout<< (char)(i+(int)'a');
			break;
		}
	}
	cout<< '\n';
	return 0;
}