#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998254768454353ll;
const int N=600050*2;
int go[N][26],root[N],tsz;
map<ll,set<ll> > has[N];
ll Hash[N];
void Add(string s)
{
	Hash[s.size()]=0;
	Hash[s.size()+1]=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		Hash[i]=((ll)Hash[i+1]*26+s[i]-'a'+1)%mod;
	}
	int *c=&root[s.size()];
	for(int i=0;i<=s.size();i++)
	{
		if(!*c) *c=++tsz;
		if(i<s.size())
		{
			has[*c][Hash[i+1]].insert(Hash[i]);
			c=&go[*c][s[i]-'a'];
		}
	}
}
bool Check(string s)
{
	Hash[s.size()]=0;
	Hash[s.size()+1]=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		Hash[i]=((ll)Hash[i+1]*26+s[i]-'a'+1)%mod;
	}
	int c=root[s.size()];
	for(int i=0;i<s.size();i++)
	{
		if(has[c][Hash[i+1]].size()>1 || (has[c][Hash[i+1]].size()==1 && *has[c][Hash[i+1]].begin()!=Hash[i])) return 1;
		c=go[c][s[i]-'a'];
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);cerr.tie(0);
	string s;
	int n,q,i;
	cin>>n>>q;
	while(n--) cin>>s,Add(s);
	while(q--) cin>>s,printf("%s\n",Check(s)?"YES":"NO");
	return 0;
}