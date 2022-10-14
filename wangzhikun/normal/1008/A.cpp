// Author : WangZhikun
// Date   : 2018.07.26

#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	char s[1010] = {0};
	cin>>s;
	int ans = 1;
	for(int i=0;i<110;i++){
		if(s[i]>='a' && s[i]<='z' && s[i] !='a'&& s[i] !='e'&& s[i] !='i'&& s[i] !='o'&& s[i] !='u'&& s[i] !='n'){
			if(s[i+1] !='a'&& s[i+1] !='e'&& s[i+1] !='i'&& s[i+1] !='o'&& s[i+1] !='u')ans = 0;
		}
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}