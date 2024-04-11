//CF1628B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n;
string s;
int hs(string s){
	int i,x=0;
	for(i=0;i<s.length();i++)
		x=x*27+s[i]-'a'+1;//cout<<s<<' '<<x<<endl;
	return x;
}
int hs2(char s0,char s1){
	string s;
	s+=s0,s+=s1;
	return hs(s);
}
int hs3(char s0,char s1,char s2){
	string s;
	s+=s0,s+=s1,s+=s2;
	return hs(s);
}
set<int> S;
int main()
{
	int T,i,f;
	char j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f=0;
		S.clear();
		for(i=1;i<=n;i++){
			cin>>s;
			S.insert(hs(s));
			if(s.length()==1)
				f=1;
			if(s.length()==2){
				if(S.find(hs2(s[1],s[0]))!=S.end())
					f=1;
				for(j='a';j<='z';j++)
					if(S.find(hs3(s[1],s[0],j))!=S.end())
						f=1;
			}
			if(s.length()==3){
				if(S.find(hs3(s[2],s[1],s[0]))!=S.end())
					f=1;
				if(S.find(hs2(s[2],s[1]))!=S.end())
					f=1;
			}
		}
		if(f)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}