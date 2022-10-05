#include <bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
	cin>>s;
	if(s.size()<=3)	return cout<<s[0]<<endl,0;
	int l=0,r=s.size()-1;
	while(r-l>=3){
		if(s[l]==s[r])			ans.push_back(s[l]),l++,r--;
		else if(s[l]==s[r-1])	ans.push_back(s[l]),l++,r-=2;
		else if(s[l+1]==s[r])	ans.push_back(s[l+1]),l+=2,r--;
		else					ans.push_back(s[l+1]),l+=2,r-=2;
	}
	cout<<ans;
	reverse(ans.begin(),ans.end());
	if(r>=l)	cout<<s[l]; 
	cout<<ans<<endl;
}