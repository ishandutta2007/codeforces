#include<bits/stdc++.h>
using namespace std;
int n,tot;
const int lim=82;
inline bool query(vector<int> S)
{
	assert(++tot<=lim);
	assert(!S.empty());
	sort(S.begin(),S.end());
	assert(S[0]>=1&&S.back()<=n);
	for(int i=0;i+1<int(S.size());++i)
		assert(S[i]!=S[i+1]);
	printf("? %d ",(int)S.size());
	for(int v:S)
		printf("%d ",v);
	cout<<endl;
	string res;
	cin>>res;
	return res=="YES";
}
inline bool query(int a)
{
	return query(vector<int>(1,a));
}
inline bool query(int a,int b)
{
	vector<int> S(1,a);
	S.push_back(b);
	return query(S);
}
inline void guess(int x)
{
	assert(x>=1&&x<=n);
	printf("! %d\n",x);
	fflush(stdout);
	string res;
	cin>>res;
	if(res==":)")
		exit(0);
}
inline vector<int> operator + (const vector<int> &a,const vector<int> &b)
{
	vector<int> c=a;
	c.insert(c.end(),b.begin(),b.end());
	return c;
}
void solve(vector<int> now)
{
	assert(!now.empty());
	int sz=now.size();
	if(sz==1)
	{
		guess(now[0]);
		assert(false);
	}
	if(sz==2)
	{
		guess(now[0]);
		guess(now[1]);
		assert(false);
	}
	if(sz==3)
	{
		bool ans=query(now[0]);
		if(ans)
		{
			guess(now[0]);
			if(query(now[1]))
				guess(now[1]);
			else
				guess(now[2]);
			assert(false);
		}
		ans=query(now[0]);
		if(ans)
		{
			guess(now[0]);
			if(query(now[1]))
				guess(now[1]);
			else
				guess(now[2]);
			assert(false);
		}
		guess(now[1]);
		guess(now[2]);
		assert(false);
	}
	vector<int> S[5];
	for(int i=0;i<sz;++i)
		S[(i&3)+1].push_back(now[i]);
	bool ans1=query(S[1]+S[2]);
	bool ans2=query(S[1]+S[3]);
	vector<int> T;
	if(ans1&&ans2)
		T=S[1]+S[2]+S[3];
	else if(ans1&&!ans2)
		T=S[1]+S[2]+S[4];
	else if(!ans1&&ans2)
		T=S[1]+S[3]+S[4];
	else
		T=S[2]+S[3]+S[4];
	solve(T);
	assert(false);
}
int main()
{
	scanf("%d",&n);
	vector<int> U(n);
	for(int i=0;i<n;++i)
		U[i]=i+1;
	solve(U);
	return 0;
}