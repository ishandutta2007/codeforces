#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
	ios::sync_with_stdio(false);
	cin>>s;
	int n=s.size(),i=n-1;
	while (i>-1&&s[i]=='1'){
		s[i]='0';
		i--;
	}
	int t=0;
	bool fg=1;
	while (i>-1){
		if (fg==1){
			while (i>-1&&s[i]=='0'){
				++t,--i;
			}
			fg=0;
		}
		else{
			while (i>-1&&s[i]=='1'){
				--t,--i;
			}
			int j=i+1;
			while (t<0&&s[j+1]=='1'){
				s[j]='0';
				++j,++t;
			}
			fg=1;
		}
	}
	cout<<s<<endl;
	return 0;
}