#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
struct Number
{
	bitset<N> bits;
	Number(){}
	void init(vector<int> s)
	{
		int c=0;
		while(s.size())
		{
			bits[c]=s[0]&1;c++;
			s[0]>>=1;
			for(int i=1;i<s.size();i++) s[i-1]+=(s[i]&1)*5,s[i]/=2;
			while(s.size() && s.back()==0) s.pop_back();
		}
	}
} a[N];
//void operator ^= (Number &a, Number b){ for(int i=0;i<N;i++) a.bits[i]^=b.bits[i];}
bitset<N> all[N];
int Gauss[N];
void Add(int id)
{
	bitset<N> st;
	for(int i=N-1;~i;i--)
	{
		if(a[id].bits[i])
		{
			if(Gauss[i])
			{
				a[id].bits^=a[Gauss[i]].bits;
				st^=all[i];
			}
			else
			{
				Gauss[i]=id;
				all[i]=st;
				all[i].set(id);
				printf("0\n");
				return;
			}
		}
	}
	printf("%i ",st.count());
	for(int i=0;i<N;i++) if(st.test(i))printf("%i ",i-1);
	printf("\n");
}
int main()
{
	int n,i,j;string s;
	vector<int> v;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		cin >> s;v.clear();
		for(j=s.size()-1;~j;j--) v.pb((int)(s[j]-'0'));
        a[i].init(v);Add(i);
	}
	return 0;
}