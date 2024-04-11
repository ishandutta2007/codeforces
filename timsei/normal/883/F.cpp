#include<iostream>
#include<cstdio>
#include<set>
#include<string>
using namespace std;
int n;
string s;
set<string> ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		cin>>s;
		for (int i=0;i<(int)s.length();++i)
			if (s[i]=='u'){
				s=s.substr(0,i)+"oo"+s.substr(i+1,s.length());
				++i;
			}else if (s[i]=='k'){
				int pos;
				for (pos=i+1;pos<(int)s.length()&&s[pos]=='k';++pos);
				if (pos<(int)s.length()&&s[pos]=='h') s=s.substr(0,i)+'h'+s.substr(pos+1,s.length());
			}
		// cout<<s<<'*'<<endl;
		ans.insert(s);
	}
	printf("%d",ans.size());
	return 0;
}