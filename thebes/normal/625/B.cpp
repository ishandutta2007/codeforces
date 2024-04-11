#include <bits/stdc++.h>
using namespace std;

string s, c; int cnt, i, j;
bool find(int p){
	for(int i=0;i<c.size();i++){
		if(s[i+p]!=c[i]) return 0;
	}
	return 1;
}

int main(){
	cin >> s >> c;
	if(c.size()>s.size()){printf("0\n"); return 0;}
	for(i=0;i<s.size()-c.size()+1;i++){
		if(find(i)){
			cnt++;
			s[i+c.size()-1]='#';
		}
	}
	printf("%d\n",cnt);
	return 0;
}