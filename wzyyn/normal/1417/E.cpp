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
const int N=9000005;
int n,nd=1;
int S[N],ch[N][2];
ll sum[35][2];
void Insert(int v){
	int x=1;
	Rep(i,29,0){
		int c=(v>>i)&1;
		if (!ch[x][c]) ch[x][c]=++nd;
		sum[i][c]+=S[ch[x][c^1]];
		x=ch[x][c]; ++S[x];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		Insert(x);
	}
	ll s1=0,s2=0;
	For(i,0,29){
		//cout<<sum[i][0]<<' '<<sum[i][1]<<endl;
		if (sum[i][0]<=sum[i][1])
			s2+=sum[i][0];
		else s2+=sum[i][1],s1+=1<<i;
	}
	cout<<s2<<' '<<s1<<endl;
}