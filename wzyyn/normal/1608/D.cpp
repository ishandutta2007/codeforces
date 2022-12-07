#include<bits/stdc++.h>

using namespace std;
const int N=100005;
const int mo=998244353;
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
int C(int x,int y){
	if (x<0||y<0||y>x) return 0;
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
char s[5];

int main(){
	init();
	int T;
	scanf("%d",&T);
	int fr=0;
	int bb=0,ww=0;
	int b=0,w=0,t1=0,t2=0;
	for (int i=1;i<=T;i++){
		scanf("%s",s+1);
		if (s[1]=='B'||s[2]=='W') t1=1;
		if (s[1]=='W'||s[2]=='B') t2=1;
		if (s[1]=='?'&&s[2]=='?') ++fr;
		else if (s[1]!='?'&&s[2]!='?'){
			if (s[1]=='B'&&s[2]=='B') ++bb;
			if (s[1]=='W'&&s[2]=='W') ++ww;
		}
		else{
			if (s[1]=='B'||s[2]=='B') ++b;
			if (s[1]=='W'||s[2]=='W') ++w;
		}
	}
	b+=fr; w+=fr;
	int ans=0;
	for (int i=0;i<=b;i++)
		ans=(ans+1ll*C(b,i)*C(w,i+bb-ww))%mo;
	b-=fr; w-=fr;
	if (!bb&&!ww){
		int vp=1;
		for (int i=1;i<=fr;i++)
			vp=1ll*vp*2%mo;
		ans=(ans+mo-vp)%mo;
	}
	ans=(ans+2-t1-t2)%mo;
	cout<<ans<<endl;
}
/*
2*bb 2*ww
1*bb 1*ww 1*wb 1*bw
*/