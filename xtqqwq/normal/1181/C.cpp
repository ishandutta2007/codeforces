#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
ll ans;
char s[1005][1005];
int lst[1005][1005],bef[1005][1005],cnt[1005][1005][26];

int get(int x,int y,int d){
	int l=1,r=y+1,mid,c=s[x][y]-'a',ret=y+1;
	while(l<=r){
		mid=(l+r)/2;
		if(cnt[x][y][c]-cnt[x-d][y][c]-cnt[x][mid-1][c]+cnt[x-d][mid-1][c]==(y-mid+1)*d) ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<26;k++)
				cnt[i][j][k]=cnt[i][j-1][k]+cnt[i-1][j][k]-cnt[i-1][j-1][k]+(s[i][j]-'a'==k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==s[i-1][j]) lst[i][j]=lst[i-1][j];
			else lst[i][j]=i-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(lst[i][j]==lst[i][j-1]&&s[i][j]==s[i][j-1]) bef[i][j]=bef[i][j-1];
			else bef[i][j]=j-1;
		}
	}
	int t1,t2,nx,tmp;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t1=lst[i][j],t2=lst[t1][j],nx=max(bef[i][j],bef[t1][j]);
			if(i-t1==t1-t2&&t2>=i-t1){
				tmp=get(t2,j,i-t1)-1;
				ans+=j-max(nx,tmp);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}