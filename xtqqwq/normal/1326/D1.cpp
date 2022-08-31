#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int r[2000005];
char t[1000005],s[2000005];

int main(){
	int T=readint();
	while(T--){
		scanf("%s",t+1);
		m=strlen(t+1);
		int now=0;
		for(int i=1;i<=m/2;i++){
			if(t[i]==t[m-i+1]) now=i;
			else break;
		}
		if(now==m/2){
			for(int i=1;i<=m;i++) printf("%c",t[i]);
			printf("\n");
			continue;
		}
		int maxr=0,pos=0;
		now=now*2;
		n=m;
		for(int i=0;i<=(n<<1);i++) r[i]=0,s[i]=0;
		for(int i=n;i>=1;i--) s[2*i-1]=t[i];
		n<<=1;
		for(int i=1;i<=n;i++){
			r[i]=1;
			if(i<=maxr) r[i]=min(r[pos*2-i],maxr-i+1);
			for(int j=r[i];j<=n;j++){
				if(i-j<0||i+j>n||s[i-j]!=s[i+j]) break;
				r[i]=j+1;
			}
			if(i+r[i]-1>maxr) maxr=i+r[i]-1,pos=i;
		}
		int ans=0,pl=0,opt=0;
		for(int i=0;i<=n;i++){
			if(i<=m&&i-r[i]+1<=now){
				if(chkmax(ans,now+(2*i-2*now)/2)){
					pl=i,opt=0;
				}
			}
			if(i>m&&i+r[i]-1>=n-now){
				if(chkmax(ans,now+(2*(n-now)-2*i)/2)){
					pl=i,opt=1;
				}
			}
		}
//		cout<<pl<<' '<<r[pl]<<' '<<opt<<' '<<now<<' '<<n-now<<endl;
		if(opt==0){
			for(int i=0;i<=2*pl-now;i++) if(s[i]) printf("%c",s[i]);
			for(int i=m-now/2+1;i<=m;i++) printf("%c",t[i]);
			printf("\n");
		}
		else{
			for(int i=1;i<=now/2;i++) printf("%c",t[i]);
			for(int i=2*pl-(n-now);i<=n;i++) if(s[i]) printf("%c",s[i]);
			printf("\n");
		}
	}
	return 0;
}