#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5+10;

char s[N],t[N],S[N];
int i,j,n,Len;
LL Ans;

struct AC{
	int t[N][26],fail[N],d[N],cnt=0,ans[N];
	queue<int> Q;
	void Push(char *s){
		for(i=0,j=1;s[j];j++){
			if(!t[i][s[j]-97])
				t[i][s[j]-97]=++cnt;
			i=t[i][s[j]-97];
		}
		d[i]++;
	}
	void Build(){
		for(i=0;i<26;i++)
			if(t[0][i])
				d[t[0][i]]+=d[0],
				Q.push(t[0][i]);
		while(!Q.empty()){
			i=Q.front();
			Q.pop();
			for(j=0;j<26;j++)
				if(t[i][j])
					fail[t[i][j]]=t[fail[i]][j],
					d[t[i][j]]+=d[fail[t[i][j]]],
					Q.push(t[i][j]);
				else
					t[i][j]=t[fail[i]][j];
		}
	}
	void work(char *s){
		for(i=0,j=1;s[j];j++){
			i=t[i][s[j]-97];
			ans[j]=d[i];
		}
	}
}T1,T2;

int main(){
	scanf("%s%d",t+1,&n);
	while(n--){
		scanf("%s",s+1);
		T1.Push(s);
		Len = strlen(s+1);
		for(i=1;i<=Len/2;i++)
			swap(s[i],s[Len-i+1]);
		T2.Push(s);
	}
	T1.Build();
	T2.Build();
	T1.work(t);
	Len = strlen(t+1);
	for(i=1;i<=Len/2;i++)
		swap(t[i],t[Len-i+1]);
	T2.work(t);
	for(i=1;i<Len;i++)
		Ans=Ans+1ll*T1.ans[i]*T2.ans[Len-i];
	printf("%lld",Ans);
	return 0;
}