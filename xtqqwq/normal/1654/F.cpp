// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cnt[26],a[270000];
pair<pii,int> b[270000];
char s[270000];

int main(){
	n=readint();
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) cnt[s[i]-'a']=1;
	for(int i=1;i<26;i++) cnt[i]+=cnt[i-1];
	for(int i=0;i<(1<<n);i++) a[i]=cnt[s[i]-'a'];
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j+=(1<<(i+1))){
			for(int k=0;k<(1<<(i+1));k++){
				if(!(k&(1<<i))) b[j+k]=mp(mp(a[j+k],a[j+(1<<i)+k]),j+k);
				else b[j+k]=mp(mp(a[j+k],a[j+k-(1<<i)]),j+k);
			}
		}
		sort(b,b+(1<<n));
		int num=0;
		for(int j=0;j<(1<<n);j++){
			if(!j||b[j].fi!=b[j-1].fi) num++;
			a[b[j].se]=num;
		}
//		cout<<"test "<<i<<endl;
//		for(int j=0;j<(1<<n);j++) cout<<a[j]<<' ';
//		cout<<endl;
	}
	int pl=0;
	for(int i=0;i<(1<<n);i++){
		if(a[i]==1){
			pl=i;
			break;
		}
	}
	for(int i=0;i<(1<<n);i++) putchar(s[i^pl]);
	putchar('\n');
	return 0;
}