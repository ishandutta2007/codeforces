#include <bits/stdc++.h>
using namespace std;

string s, t;
int pos, l, r, cnt, i;

int main(){
	cin >> s >> t;
	for(i=0;i<t.size();i++){
		if(t[i]==s[pos]) pos++;
		if(pos==s.size()){l=i; break;}
	}
	for(pos=s.size()-1,i=t.size()-1;i>=0;i--){
		if(t[i]==s[pos]) pos--;
		if(pos==-1){r=i; break;}
	}
	printf("%d\n",max(0,r-l));
	return 0;
}