#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),a[100005],cnt[100005],sum1=0,sum2=0,sum3=0,sum4=0;
signed main(){
	fz(i,1,n) a[i]=read(),cnt[a[i]]++;
	fz(i,1,100000) if(cnt[i]>=2) sum1++;
	fz(i,1,100000) if(cnt[i]>=4) sum2++;
	fz(i,1,100000) if(cnt[i]>=6) sum3++;
	fz(i,1,100000) if(cnt[i]>=8) sum4++;
//	cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
	int q=read();while(q--){
		char c;int x;cin>>c>>x;
		if(c=='+'){
			cnt[x]++;
			if(cnt[x]==2) sum1++;
			if(cnt[x]==4) sum2++;
			if(cnt[x]==6) sum3++;
			if(cnt[x]==8) sum4++;
		}
		else{
			cnt[x]--;
			if(cnt[x]==1) sum1--;
			if(cnt[x]==3) sum2--;
			if(cnt[x]==5) sum3--;
			if(cnt[x]==7) sum4--;
		}
		if((sum3>=1&&sum1>=2)||(sum2>=1&&sum1>=3)||(sum2>=2)||(sum4>=1)) puts("YES");
		else puts("NO");
	}
	return 0;
}