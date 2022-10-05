#include <bits/stdc++.h>
using namespace std;
int main(){
	int len;
	cin>>len;
	string str;
	cin>>str;
	string ans;
	int cur=0,cnt=0;
	while(cnt<str.size()){
		cur++;
		ans.push_back(str[cnt]);
		cnt+=cur;
	}
	cout<<ans<<endl;
}//