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
using namespace std;
const int N=1<<14;
vector<int> e[N];
int in[N],n,top,S;
char ans[500005],s[5];
void dfs(int x){
	for (;e[x].size();){
		int to=e[x].back();
		e[x].pop_back();
		dfs(to);
	}
	ans[++top]=x%128;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s+1);
		int id1=s[1]*128+s[2];
		int id2=s[2]*128+s[3];
		//cout<<id1<<' '<<id2<<endl;
		e[id1].PB(id2); in[id2]++;
	}
	For(i,0,N-1)
		if (abs((int)e[i].size()-in[i])>1){
			//cout<<e[i].size()<<' '<<in[i]<<' '<<i<<endl;
			return puts("NO"),0;
		}
	S=-1;
	For(i,0,N-1)
		if (in[i]==e[i].size()-1)
			if (S==-1) S=i;
			else return puts("NO"),0;
	if (S==-1)
		For(i,0,N-1)
			if (e[i].size())
				S=i;
	dfs(S);
	//ans[++top]=S%128;
	ans[++top]=S/128;
	reverse(ans+1,ans+top+1);
	if (top!=n+2) return puts("NO"),0;
	printf("YES\n%s\n",ans+1);
}