// LUOGU_RID: 90774623
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int n,m;
int fib[50];
char s[1005];
int get(int p){
	for(int i=31;i>=2;i--)if(p>fib[i])p-=fib[i];
	return p==1;
}
bool check(int p){
	for(int i=1;i<=31;i++)if(p==fib[i])return 1;
	return 0;
}
vector<pair<int,int> >v,v1; 
int main(){
	fib[0]=1,fib[1]=1;
	for(int i=2;i<=31;i++)fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&n);
	int sum=1;v.push_back(make_pair(0,1));
	while(n--){
		scanf("%s",s+1);
		int l=strlen(s+1);
		int now;
		for(int i=1;i<=l;i++){
			now=sum;
			v1.clear();
			for(auto p:v){
				if(p.first==i+m-1||get(i+m-p.first)==s[i]-'0'){
					if(check(i+m-p.first))now=add(now,mod-p.second);
					if(p.first<i+m-1||s[i]=='1')v1.push_back(p);
				}
			}
			v=v1;
			v.push_back(make_pair(i+m,now));
			sum=add(sum,now);
		}
		m+=l;
		printf("%d\n",now);
	}
	return 0;
}