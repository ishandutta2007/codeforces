#include<bits/stdc++.h>
using namespace std;
int const N=60005;
int n,m,cnt,f[N],mp[2][N];
string s;
inline int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
inline void mg(int x,int y)
{
	int fx=fa(x),fy=fa(y);
	if(fx!=fy)
		f[fx]=fy,cnt--;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int op=1;n--;op^=1)
	{
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			int t=s[i]<58?s[i]^48:(s[i]^64)+9;
			for(int p=0;p<4;p++)
				cnt+=mp[op][i<<2|p]=t>>3-p&1;
		}
		for(int i=0;i<m;i++)
			f[op*m+i]=op*m+i;
		for(int i=0;i<m;i++)
		{
			if(mp[op][i])
			{
				if(mp[op^1][i])
					mg((op^1)*m+i,op*m+i);
				if(i<m-1&&mp[op][i+1])
					mg(op*m+i,op*m+i+1);
			}
		}		
	}
	cout<<cnt<<endl;
	return 0;
}