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

int n,k;
int a[10005],b[10005],val[10005];

int askor(int x,int y){
	printf("or %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int askand(int x,int y){
	printf("and %d %d\n",x,y);
	fflush(stdout);
	return readint();
}

int main(){
	n=readint(); k=readint();
	for(int i=2;i<=n;i++){
		a[i]=askor(1,i);
		b[i]=askand(1,i);
	}
	int pl=-1;
	vector<int> vec(0);
	for(int i=0;i<30;i++){
		bool hv=0;
		for(int j=2;j<=n;j++){
			if(((a[j]-b[j])>>i)&1);
			else{
				if((a[j]>>i)&1) val[1]+=1<<i;
				hv=1;
				break;
			}
		}
		if(hv){
			for(int j=2;j<=n;j++){
				int t=((a[j]-b[j])>>i)&1;
				t^=(val[1]>>i)&1;
				val[j]+=t<<i;
			}
		}
		else{
			vec.pb(i);
			val[1]+=1<<i;
		}
	}
	if(vec.size()){
		int tmp=askor(2,3);
		for(auto pl:vec){
			if((tmp>>pl)&1){
				for(int i=1;i<=n;i++) val[i]^=1<<pl;
			}
		}
	}
	sort(val+1,val+n+1);
	printf("finish %d\n",val[k]);
	fflush(stdout);
	return 0;
}