#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=1<<20|5;
map<char,int> mp;
char tab[25],s[5005];
int m,n,a,b;
int mn[N],mx[N],S[N];
int f[N],fl[N];
int Idx(char c){
	if (!mp.count(c)){
		mp[c]=m;
		tab[m++]=c;
	}
	return mp[c];
}
int main(){
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	For(i,0,1<<20) mn[i]=1<<30,mx[i]=0;
	For(i,1,n){
		int x=Idx(s[i]);
		mn[1<<x]=min(mn[1<<x],i);
		mx[1<<x]=max(mx[1<<x],i);
		S[1<<x]++;
	}
	if (m==1){
		printf("1 %c\n",tab[0]);
		return 0;
	}
	For(j,0,(1<<m)-1) For(i,0,m-1)
		if (j&(1<<i)){
			mn[j]=min(mn[j],mn[1<<i]);
			mx[j]=max(mx[j],mx[1<<i]);
			S[j]=S[j^(1<<i)]+S[1<<i];
		}
	f[0]=1;
	For(i,0,(1<<m)-1){
			int S1=0;
			For(j,0,m-1) if (i&(1<<j)){
				S1+=(1<<j);
				if (f[S1]&&f[S1^i]) f[i]=1;
				if (f[i^(1<<j)]&&(mx[i]-mn[i]+1)*a<=S[i]*b) f[i]=1;
			}
		}
	vector<char> ans;
	For(i,0,m-1)
		if (f[(1<<m)-1-(1<<i)])
			ans.PB(tab[i]);
	sort(ans.begin(),ans.end());
	printf("%d",ans.size());
	for (auto i:ans) printf(" %c",i);
}
/*
20 1 1
abcdefghijjihgfedcba
*/