#include<bits/stdc++.h>

using namespace std;

const int N=500005;
const int base=1919811;
unsigned long long key[30],pw[N],hsh[N];
vector<unsigned long long> h[N],q[N];
map<unsigned long long,int> A,B,id,mp[N];
long long ans;
string s[N];
int n,m,cnt,d[N];
int ch[N][26];

void Merge(map<unsigned long long,int> &A,map<unsigned long long,int> &B){
	if (A.size()<B.size()) swap(A,B);
	for (auto i:B) A[i.first]+=i.second;
	B.clear();
}
void dfs(int x){
	for (int i=0;i<26;i++)
		if (ch[x][i]){
			dfs(ch[x][i]);
			Merge(mp[x],mp[ch[x][i]]);
		}
	for (auto i:q[x])
		ans-=mp[x][i];
}
int main(){
	srand(time(NULL));
	for (int i=0;i<26;i++)
		for (int j=0;j<=63;j++)
			key[i]=key[i]*2+rand()%2;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		cin>>s[i];
	m=s[1].length();
	for (int i=1;i<=n;i++){
		h[i].resize(m+1);
		h[i][0]=0;
		for (int j=1;j<=m;j++){
			h[i][j]=h[i][j-1]*base+key[s[i][j-1]-'a'];
			hsh[i]+=key[s[i][j-1]-'a'];
		}
		
		if (!id[hsh[i]])
			id[hsh[i]]=++cnt;
		++A[hsh[i]];
		++B[h[i][m]];
	}
	ans=1ll*n*(n-1)/2*1337;
	for (auto i:A)
		ans-=1ll*i.second*(i.second-1)/2*1335;
//	cout<<ans<<endl;
	for (int i=1;i<=n;i++){
		int las,x;
		las=x=id[hsh[i]];
		for (int j=m-1;j>=0;j--){
			int c=s[i][j]-'a';
			if (!ch[x][c]) ch[x][c]=++cnt;
			x=ch[x][c];
			if (!j||(s[i][j]<s[i][j-1])){
//				cout<<i<<' '<<j<<' '<<las<<' '<<x<<' '<<h[i][j]<<endl;
				q[las].push_back(h[i][j]);
				las=x; ++d[i];
			}
		}
		for (int j=0;j<=m;j++)
			++mp[x][h[i][j]];
	}
	for (int i=1;i<=A.size();i++)
		dfs(i);
	
//	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
		ans+=1ll*B[h[i][m]]*d[i];
	for (auto i:B)
		ans-=2ll*i.second*(i.second-1)/2;
	cout<<ans<<endl; 
}