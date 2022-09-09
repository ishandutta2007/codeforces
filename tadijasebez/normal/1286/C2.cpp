#include <bits/stdc++.h>
using namespace std;
const int N=150;
char s[N];
int cnt[N][26];
int has[N][26];
char ans[N];
string pf[N];
int main(){
	int n;
	scanf("%i",&n);
	printf("? 1 %i\n",n);
	fflush(stdout);
	for(int k=1;k<=n*(n+1)/2;k++){
		scanf("%s",s);
		int m=strlen(s);
		for(int i=0;i<m;i++){
			cnt[m][s[i]-'a']++;
		}
		if(n==1){
			printf("! %s\n",s);
			fflush(stdout);
			return 0;
		}
	}
	for(int i=1;i<=(n+1)/2;i++){
		for(int j=0;j<26;j++){
			has[i][j]=cnt[i][j]-cnt[i-1][j];
		}
	}
	for(int i=1;i<=(n+1)/2;i++){
		for(int j=0;j<26;j++){
			has[i][j]-=has[i+1][j];
		}
	}
	int m=(n+1)/2;
	printf("? 1 %i\n",m);
	fflush(stdout);
	multiset<string> pref;
	for(int i=1;i<=m*(m+1)/2;i++){
		string s;cin>>s;
		sort(s.begin(),s.end());
		pref.insert(s);
	}
	if(m==1){
		ans[1]=(*pref.begin())[0];
		has[1][ans[1]-'a']--;
	}else{
		printf("? 2 %i\n",m);
		fflush(stdout);
		for(int i=1;i<=m*(m-1)/2;i++){
			string s;cin>>s;
			sort(s.begin(),s.end());
			pref.erase(pref.find(s));
		}
		for(auto st:pref)pf[st.size()]=st;
		for(int i=1;i<=m;i++){
			multiset<char> chs;
			for(char c:pf[i])chs.insert(c);
			for(char c:pf[i-1])chs.erase(chs.find(c));
			ans[i]=*chs.begin();
			has[i][ans[i]-'a']--;
		}
	}
	for(int i=1;i*2<=n;i++){
		for(int j=0;j<26;j++){
			if(has[i][j])ans[n-i+1]='a'+j;
		}
	}
	printf("! %s\n",ans+1);
	fflush(stdout);
	return 0;
}