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
char s[100005][5];
int bk[700],bk1[20005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) scanf("%s",s[i]);
		bool fl=0;
		for(int i=0;i<26*26;i++) bk[i]=0;
		for(int i=0;i<26*26*26;i++) bk1[i]=0;
		for(int i=1;i<=n;i++){
			int l=strlen(s[i]);
			if(l==1) fl=1;
			else if(l==2){
				if(s[i][0]==s[i][1]) fl=1;
				if(bk[(s[i][0]-'a')*26+(s[i][1]-'a')]) fl=1;
				for(int j=0;j<26;j++){
					if(bk1[j*26*26+(s[i][0]-'a')*26+(s[i][1]-'a')]) fl=1;
				}
				bk[(s[i][1]-'a')*26+(s[i][0]-'a')]=1;
			}
			else if(l==3){
				if(s[i][0]==s[i][2]) fl=1;
				if(bk[(s[i][1]-'a')*26+(s[i][2]-'a')]) fl=1;
				if(bk1[(s[i][0]-'a')*26*26+(s[i][1]-'a')*26+(s[i][2]-'a')]) fl=1;
				bk1[(s[i][2]-'a')*26*26+(s[i][1]-'a')*26+(s[i][0]-'a')]=1;
			}
		}
		if(fl){
			printf("YES\n");
			continue; 
		}
		else printf("NO\n");
	}
	return 0;
}