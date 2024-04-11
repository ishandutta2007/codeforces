#include<bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int N=100+5;
char s[N];
int num[N];
vector<int> st;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		st.clear();
		for(int i=0;i<n;i++) st.push_back(s[i]-'0');
		int cnt=0;
		while(1)
		{
			bool flag=true;
			int id;
			for(int i=0;i+1<st.size();i++)
				if(st[i]!=st[i+1])
				{
					flag=false;
					id=i;
					break;
				}
			if(flag) break;
			cnt++;
			for(int i=0;i<st.size();i++) num[i]=st[i];
			int n=st.size();
			st.clear();
			for(int i=0;i<n;i++)
				if(i!=id&&i!=id+1) st.push_back(num[i]);
		}
		printf((cnt&1)?"DA\n":"NET\n");
	} 
	return 0;
}