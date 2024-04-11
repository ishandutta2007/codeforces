#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n;
char s[1005];
char t[1005];
int sum[1005],pre[1005],suf[1005],anscnt=-1,ansl=1,ansr=1;
int main(){
	cin>>n>>s+1;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')	cnt1++;
		else			cnt2++;
	}
	if(cnt1!=cnt2)	return puts("0\n1 1"),0;
	bool fst=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(s[l]==s[r]&&fst)	continue;
			if(s[l]==s[r])	fst=1;
			swap(s[l],s[r]);
			for(int i=1;i<=n;i++){
				t[i]=s[i];
				t[i+n]=s[i];
			}
			for(int i=1;i<=n*2;i++){
				if(t[i]=='(')	sum[i]=sum[i-1]+1;
				else			sum[i]=sum[i-1]-1;
			}
			suf[n+1]=0x3f3f3f3f;
			pre[0]=0x3f3f3f3f;
			for(int i=1;i<=n;i++)	pre[i]=min(pre[i-1],sum[i]);
			for(int i=n;i>=1;i--)	suf[i]=min(suf[i+1],sum[i]);
			int cl=1,cr=0,cnt=0;
			for(int i=1;i<=n;i++){
				int x=min(pre[cr],suf[cl]);
				if(x-sum[cl-1]==0)	cnt++;
				cl++;cr++;
			}
			if(cnt>anscnt){
				anscnt=cnt;ansl=l;ansr=r;
			}
			swap(s[l],s[r]);
		}
	}
	cout<<anscnt<<endl<<ansl<<" "<<ansr<<endl;
	return 0;
}