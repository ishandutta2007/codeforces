#include <bits/stdc++.h>
using namespace std;

string s; int N, i;
unordered_set<string> st;
bool compress(){
	bool done = 0; int i=0;
	for(;i<(signed)s.size()-1;i++){
		if(s[i]=='k'&&s[i+1]=='h'){
			s[i] = 'h'; s.erase(s.begin()+i+1); 
			done=1; i--;
		}
		else if(s[i]=='u'){
			s[i] = 'o'; s.insert(i,"o"); 
			done=1; 
		}
	}
	if(s[i]=='u'){
		s[i] = 'o'; s.insert(i,"o"); 
		done=1; 
	}
	return done;
}

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		cin >> s;
		while(compress()){}
		st.insert(s);
	}
	printf("%d\n",(signed)st.size());
	return 0;
}