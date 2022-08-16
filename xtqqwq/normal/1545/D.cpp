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

int m,k;
ll s[1005],s2[1005];

int main(){
	m=readint(); k=readint();
	for(int i=0;i<k;i++){
		for(int j=1;j<=m;j++){
			int x=readint();
			s[i]+=x,s2[i]+=1ll*x*x;
		}
	}
	ll sv=(s[k-1]-s[0])/(k-1),dif1,dif2,ans1;
	for(int i=1;i<k-1;i++){
		if(s[i]!=s[0]+i*sv){
			ans1=i;
			dif1=s[0]+i*sv-s[i];
			break;
		}
	}
	ll tmp,nd,nv;
	if(ans1>2){
		tmp=(s2[2]-s2[1])-(s2[1]-s2[0]);
		nd=s2[2]-s2[1];
		nv=s2[2];
		for(int i=3;i<k;i++){
			nd+=tmp;
			nv+=nd;
			if(i==ans1){
				dif2=nv-s2[i];
				break;
			}
		}
	}
	else{
		tmp=(s2[6]-s2[5])-(s2[5]-s2[4]);
		nd=s2[5]-s2[4];
		nv=s2[4];
		for(int i=3;i>=0;i--){
			nd-=tmp;
			nv-=nd;
			if(i==ans1){
				dif2=nv-s2[i];
				break;
			}
		}
	}
	printf("%lld %lld\n",ans1,(dif2-1ll*dif1*dif1)/(2*dif1)+dif1);
	fflush(stdout);
	return 0;
}