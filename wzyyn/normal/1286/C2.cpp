#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh

#define ST vector<vector<string>>
using namespace std;
const int N=105;
map<string,int> mp[N];
string s[N];
char ans[N];
int n;
void query(int l,int r,int v){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	For(i,l,r) For(j,i,r){
		string s; cin>>s;
		sort(s.begin(),s.end());
		mp[s.length()][s]+=v;
	}
}
char get(string a,string b){
	a=a+"@";
	int l=a.length();
	For(i,0,l-1) if (a[i]!=b[i]) return b[i];
}
string sub(string a,char b){
	string ans;
	int n=a.length(),fl=0;
	For(i,0,n-1)
		if (a[i]!=b||fl)
			ans=ans+a[i];
		else fl=1;
	return ans;
}
int main(){
	scanf("%d",&n);
	if (n<=3){
		For(i,1,n){
			printf("? %d %d\n",i,i);
			fflush(stdout);
			scanf("%s",ans+i);
		}
	}
	else{
		int m=(n+1)/2;
		query(1,m,1);
		query(2,m,-1);
		For(i,1,n) for (auto j:mp[i])
			if (j.se) s[i]=j.fi;
		For(i,1,m) ans[i]=get(s[i-1],s[i]);
		//printf("MID %s\n",ans+1);
		For(i,1,n) mp[i].clear();
		query(1,n,1);
		string T,TT;
		for (auto i:mp[n]) T=i.fi;
		TT=T;
		Rep(i,n,m+1){
			int l=i-1;
			For(j,2,n-l+1){
				string S=T;
				For(k,1,j-1) S=sub(S,ans[k]);
				For(k,j+l,n) S=sub(S,ans[k]);
				mp[l][S]--;
			}
			string S;
			for (auto j:mp[l])
				if (j.se) S=j.fi;
			ans[i]=get(S,TT); TT=S;
		}
	}
	printf("! %s\n",ans+1);
}