#include<bits/stdc++.h>
using namespace std;

int n=0;
string s;
vector<int> vec;

int main(){
	cin>>s;
	n=s.size();
	int l=0,r=n-1;
	while (l<=r-3){
		int cnt[]={0,0,0};
		cnt[s[l]-'a']++, cnt[s[r]-'a']++, cnt[s[l+1]-'a']++, cnt[s[r-1]-'a']++;
		for (int i=0;i<3;++i){
			if (cnt[i]>1) {
				vec.push_back(i); break;
			}
		}
		l+=2,r-=2;
	}
	for (auto c:vec){
		printf("%c",c+'a');
	}
	if (l<=r) printf("%c",s[l]);
	for (int i=vec.size()-1;i>-1;--i){
		printf("%c",vec[i]+'a');
	}
	return 0;
}