#include <bits/stdc++.h>
using namespace std;
string str;
stack <int> res;
int ans;
int main()
{
	cin>>str;
	int siz=str.size();
	for(int i=0;i<siz;i++)
		if(!res.empty()&&res.top()==str[i]) ans^=1,res.pop();
		else res.push(str[i]);
	printf(ans==1?"Yes":"No");
	return 0;
}