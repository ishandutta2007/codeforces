#include <bits/stdc++.h>
using namespace std;

string s; int i, j, ans;
bool idfk(int i,int j){
	for(int wtf=0;wtf<=j-i;wtf++)
		if(s[wtf+i]!=s[j-wtf]) return 1;
	return 0;
}

int main(){
	cin >> s;
	for(i=0;i<s.size();i++){
		for(j=i;j<s.size();j++)
			if(idfk(i,j)) ans=max(j-i+1,ans);
	}
	printf("%d\n",ans);
	return 0;
}