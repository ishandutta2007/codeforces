#include<bits/stdc++.h> 
using namespace std;
int n;
char s[110000],t[110000];
int nxt[110000];
int h[110000];
int x[110000];
int f(int i){
	int ans=0;
	for(int j=i;j;j-=(j&(-j)))ans+=x[j];
	return ans;
}
void add(int i,int xx){
	for(int j=i;j<=n;j+=(j&(-j)))x[j]+=xx;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n;
		scanf("%s%s",s+1,t+1);
		for(int i=0;i<26;i++)h[i]=n+1; 
		for(int i=n;i;i--){
			nxt[i]=h[s[i]-'a'];
			h[s[i]-'a']=i;
		}
		for(int i=1;i<=n;i++)x[i]=0;
		long long ans=1000000000000000000ll,now=0;
		for(int i=1;i<=n;i++){
			int e=n+1;
			for(int j=0;j<t[i]-'a';j++)e=min(e,h[j]);
			if(e<=n)ans=min(ans,now+e-1-f(e));
			if(h[t[i]-'a']==n+1)break;
			now+=h[t[i]-'a']-1-f(h[t[i]-'a']);
			add(h[t[i]-'a'],1);
			h[t[i]-'a']=nxt[h[t[i]-'a']];
		}
		cout<<(ans==1000000000000000000ll ? -1 : ans)<<"\n"; 
	}
	return 0;
}