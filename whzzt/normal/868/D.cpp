#include<bits/stdc++.h>

using namespace std;

const int N=205,M=35;
const int lim=30;

struct String{
	set<int>s[M];
	string l,r;
	void insert(string s){
		for(int i=0;i<s.length();i++){
			int ch=0,p=1;
			for(int j=i;j<s.length()&&p<=lim;j++,p++){
				ch=(ch<<1)+s[j]-'0';
				this->s[p].insert(ch);
			}
		}
	}
	void init(char*s){
		int len=strlen(s);
		for(int i=0;i<len&&l.length()<lim;i++)l+=s[i];
		for(int i=max(0,len-lim);i<len;i++)r+=s[i];
		string now="";
		for(int i=0;i<len;i++)now+=s[i];
		insert(now);
	}
	int calc(){
		int ans=1;
		while(s[ans].size()==(1<<ans))ans++;
		return ans-1;
	}
}a[N];

char str[N];
int n,m;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",str);
		a[i].init(str);
	}
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		String&A=a[u], &B=a[v], &C=a[n+i];
		for(int j=0;j<lim;j++){
			for(auto it:A.s[j])C.s[j].insert(it);
			for(auto it:B.s[j])C.s[j].insert(it);
		}
		C.l=A.l;
		if(C.l.length()<lim){
			C.l+=B.l;
			while(C.l.length()>lim) C.l.pop_back();
		}
		C.r=B.r;
		if(C.r.length()<lim){
			C.r=A.r+B.r;
			string now="";
			if(C.r.length()>lim){
				int l=C.r.length();
				for(int i=C.r.length()-lim;i<C.r.length();i++)now+=C.r[i];
				C.r=now;
			}
		}
		C.insert(A.r+B.l);
		printf("%d\n",C.calc());
	}
	return 0;
}