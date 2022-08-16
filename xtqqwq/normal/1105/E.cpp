#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000009;
int n,m,maxa,cnt,num;
int c[45][45],t[100005];
vector<int> cur;
map<string,int> mp;

void dfs(int u){
	if(u>m){
		maxa=max(maxa,(int)cur.size());
		return;
	}
	bool fl=1;
	for(int i=0;i<cur.size();i++){
		if(c[u][cur[i]]){
			fl=0;
			break;
		}
	}
	if(fl){
		cur.push_back(u);
		dfs(u+1);
		cur.pop_back();
	}
	if(cur.size()+m-u>maxa) dfs(u+1);
}

int main(){
	n=readint(); m=readint();
	int opt,x,h; string str;
	for(int i=1;i<=n;i++){
		opt=readint();
		if(opt==1){
			if(!cnt) continue;
			sort(t+1,t+cnt+1);
			cnt=unique(t+1,t+cnt+1)-t-1;
			for(int j=1;j<=cnt;j++) for(int k=j+1;k<=cnt;k++) c[t[j]][t[k]]=c[t[k]][t[j]]=1;
			cnt=0;
		}
		else{
			cin>>str;
			if(mp.find(str)==mp.end()) mp[str]=++num;
			t[++cnt]=mp[str];
		}
	}
	if(cnt){
		sort(t+1,t+cnt+1);
		cnt=unique(t+1,t+cnt+1)-t-1;
		for(int j=1;j<=cnt;j++) for(int k=j+1;k<=cnt;k++) c[t[j]][t[k]]=c[t[k]][t[j]]=1;
		cnt=0;
	}
	dfs(1);
	cout<<maxa<<endl;
	return 0;
}