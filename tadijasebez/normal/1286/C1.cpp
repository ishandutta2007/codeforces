#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%i",&n);
	multiset<string> all;
	string str;
	printf("? 1 %i\n",n);
	fflush(stdout);
	for(int i=1;i<=n*(n+1)/2;i++) cin>>str,sort(str.begin(),str.end()),all.insert(str);
	if(n==1) return cout<<"! "<<*all.begin()<<endl,0;
	printf("? 2 %i\n",n);
	fflush(stdout);
	for(int i=1;i<=n*(n-1)/2;i++) cin>>str,sort(str.begin(),str.end()),all.erase(all.find(str));
	vector<string> ss(n+1);
	for(auto s:all) ss[s.size()]=s;
	printf("! ");
	for(int i=1;i<=n;i++)
	{
		multiset<char> st;
		for(int j=0;j<ss[i].size();j++) st.insert(ss[i][j]);
		for(int j=0;j<ss[i-1].size();j++) st.erase(st.find(ss[i-1][j]));
		printf("%c",*st.begin());
	}
	printf("\n");
	fflush(stdout);
	return 0;
}