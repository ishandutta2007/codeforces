//by xay5421 2449670833@qq.com
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;typedef unsigned long long ull;typedef pair<int,int>pii;typedef vector<int>VI;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=400005;
int n,m,a[N],mx[N],ans[N];vector<int>res[N];
struct node{
	int x,cnt;
	bool operator<(const node&b)const{return cnt<b.cnt;}
}b[N];
signed main(){
	rd(n);
	for(int i=1;i<=n;++i)rd(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;){
		int j=i+1;
		while(j<=n&&a[i]==a[j])++j;
		b[++m]=(node){a[i],j-i};
		i=j;
	}
	std::sort(b+1,b+1+m);
	int lst=0;
	for(int i=1;i<=m;++i){
		for(int j=lst+1;j<=lst+b[i].cnt;++j){
			mx[j]=max(mx[j-1],j-lst);
		}
		lst+=b[i].cnt;
	}
	int maxi=1,maxj=1;
	int now=1,tot=0;
	for(int i=1;i<=n;++i){
		while(now<=m&&b[now].cnt<i)tot+=b[now].cnt,++now;
		ans[i]=tot+1ll*(m-now+1)*i;
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;j+=i){
			if(j>maxj&&ans[min(i,j/i)]>=j){
				maxi=i,maxj=j;
			}
		}
	}
	pt(maxj,'\n');
	maxj=maxj/maxi;
	pt(maxi,' '),pt(maxj,'\n');
	for(int i=0;i<maxi;++i)res[i].resize(maxj);
	int x=0,y=0,tmp=0;
	for(int i=1;i<=maxi*maxj;++i){
		if(b[m].cnt==0)--m;
		b[m].cnt=min(b[m].cnt,min(maxi,maxj));
		--b[m].cnt,res[x][y]=b[m].x;
		if(x==maxi-1){
			x=0,y=++tmp;
		}else{
			++x,++y%=maxj;
		}
	}
	for(int i=0;i<maxi;++i)for(int j=0;j<maxj;++j){
		pt(res[i][j],j==maxj-1?'\n':' ');
	}
	return 0;
}