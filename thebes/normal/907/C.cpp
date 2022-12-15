#include <bits/stdc++.h>
using namespace std;

int p[30], u[30], N, i, x, ans;
string s; char c, l; bool d;

bool det(){
	int pos=0;
	for(int i=0;i<26;i++){
		pos += !p[i];
		if(!p[i]) l=i+'a';
	}
	return(pos==1);
}

int main(){
	for(scanf("%d",&N),i=0;i<N;i++){
		cin >> c >> s;
		memset(u, 0, sizeof(u));
		for(char a : s){
			if(c == '!') u[a-'a']=1;
			if(c == '.') p[a-'a']=1;
		}
		for(int j=0;j<26;j++){
			if(c == '!' && !u[j]) p[j]=1;
		}
		if(c == '?' && d && l != s[0]) ans++;
		if(c == '!' && d) ans++;
		if(c == '?') p[s[0]-'a']=1;
		d = det();
	}
	printf("%d\n",ans);
	return 0;
}