#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int LEN=100,bas=8;
const int mod=100000000;
struct Big{
	int a[LEN];
	Big(){
		memset(a,0,sizeof(a));
	}
	
	void input(){
		static char s[LEN*bas];
		scanf("%s",s+1);
		a[0]=strlen(s+1);
		reverse(s+1,s+a[0]+1);
		Rep(i,a[0],1) a[(i-1)/bas+1]=a[(i-1)/bas+1]*10+s[i]-'0';
		a[0]=(a[0]-1)/bas+1;
	}
	void write(){
		printf("%d",a[a[0]]);
		Rep(i,a[0]-1,1) printf("%08d",a[i]);
	}
	void writeln(){
		write();
		puts("");
	}
	
	int& operator [](int x){
		return a[x];
	}
	const int& operator [](int x)const{
		return a[x];
	}
	
	void normalize(){
		for (;a[0]&&!a[a[0]];--a[0]);
	}
	
	
	bool operator <(const Big &b)const{
		if (a[0]!=b[0]) return a[0]<b[0];
		Rep(i,a[0],1)
			if (a[i]!=b[i])
				return a[i]<b[i];
		return 0;
	}
	bool operator ==(const Big &b)const{
		if (a[0]!=b[0]) return 0;
		Rep(i,a[0],1)
			if (a[i]!=b[i])
				return 0;
		return 1;
	}
	bool operator >(const Big &b)const{
		return !((*this)==b)&&!((*this)<b);
	}
	bool operator !=(const Big &b)const{
		return !((*this)==b);
	}
	bool operator <=(const Big &b)const{
		return !((*this)>b);
	}
	bool operator >=(const Big &b)const{
		return !((*this)<b);
	}

	Big operator +(const Big &b)const{
		Big ans;
		ans[0]=max(a[0],b[0]);
		For(i,1,ans[0]) ans[i]=a[i]+b[i];
		For(i,1,ans[0]){
			ans[i+1]+=ans[i]/mod;
			ans[i]%=mod;
		}
		ans[0]++;
		ans.normalize();
		return ans;
	} 
	Big operator -(const Big &b)const{
		Big ans;
		ans[0]=a[0];
		For(i,1,ans[0]) ans[i]=a[i]-b[i];
		For(i,1,ans[0]) if (ans[i]<0)
			ans[i]+=mod,ans[i+1]--;
		ans.normalize();
		return ans;
	}
	Big operator *(const int &v)const{
		Big ans;
		ll x=0;
		ans[0]=a[0];
		For(i,1,a[0]){
			x+=1ll*a[i]*v;
			ans[i]=x%mod;
			x/=mod;
		}
		ans[++ans[0]]=x;
		ans.normalize();
		return ans;
	}
	Big operator *(const Big &b)const{
		Big ans;
		ans.a[0]=a[0]+b[0];
		For(i,1,a[0]){
			ll x=0;
			For(j,1,b[0]){
				x+=ans[i+j-1]+1ll*a[i]*b[j];
				ans[i+j-1]=x%mod;
				x/=mod;
			}
			ans[i+b[0]]=x;
		}
		ans.normalize();
		return ans;
	}
	Big operator /(const int &v)const{
		Big ans;
		ll x=0;
		ans[0]=a[0];
		Rep(i,a[0],1){
			x=x*mod+a[i];
			ans[i]=x/v;
			x%=v;
		}
		ans.normalize();
		return ans;
	}
	Big operator /(const Big &b)const{
		int lv=0;
		Big bb=b,aa=(*this),ans;
		for (;bb<=aa;bb=bb*10,++lv);
		ans.a[0]=(lv-1)/bas+1;
		for (bb=bb/10;lv;--lv){
			int val=0;
			for (;bb<=aa;aa=aa-bb,val++);
			ans.a[(lv-1)/bas+1]=(ans.a[(lv-1)/bas+1]*10+val)%mod;
			bb=bb/10;
		}
		return ans;
	}
	Big operator %(const Big &b)const{
		int lv=0;
		Big bb=b,aa=(*this);
		for (;bb<=aa;bb=bb*10,++lv);
		for (bb=bb/10;lv;--lv){
			for (;bb<=aa;aa=aa-bb);
			bb=bb/10;
		}
		return aa;
	}
};
Big gcd(Big x,Big y){
	Big ans;
	ans.a[0]=ans.a[1]=1;
	/*x.write(); putchar(' ');
	y.write(); putchar(' ');
	puts("YYN");*/
	for (;;){
		if (x.a[0]==0) return y*ans;
		if (y.a[0]==0) return x*ans;
		for (;x.a[1]%2==0&&y.a[1]%2==0;)
			x=x/2,y=y/2,ans=ans*2;
		for (;x.a[1]%2==0;x=x/2);
		for (;y.a[1]%2==0;y=y/2);
		if (x==y) return x*ans;
		if (x<y) y=y-x;
		else x=x-y;
	}
}
int rnd(){
	int x=0;
	For(i,1,8)
		x=x*10+rand()%10;
	return x;
}
Big Rand(Big x){
	Big ans;
	ans[0]=x[0]+10;
	For(i,1,ans[0]) ans[i]=rnd()%mod;
	ans.normalize();
	//ans.writeln();
	//x.writeln();
	return ans%x;
}
Big q[205];
int top;
void insert(Big x){
	int p=++top; q[p]=x;
	Rep(i,p-1,1){
		Big v=gcd(q[i],q[p]);
		if (v.a[0]!=1||v.a[1]!=1)
			q[i]=q[i]/v,q[p]=q[p]/v,q[++top]=v;
	}
	int tmp=top; top=0;
	For(i,1,tmp)
		if (q[i].a[0]!=1||q[i].a[1]!=1)
			q[++top]=q[i];
}
int main(){
	srand(time(NULL));
	Big n;
	n.input();
	q[++top]=n;
	For(T,1,15){
		Big x;
		for (;;){
			for (;!x[0];x=Rand(n));
			//x.writeln();
			Big tmp=gcd(x,n);
			if (tmp[0]!=1||tmp[1]!=1) insert(tmp);
			else break;
			x=Rand(n);
		}
		printf("sqrt ");
		(x*x%n).writeln();
		fflush(stdout);
		Big y; y.input();
		if (y!=x&&y!=n-x)
			insert(gcd(n,(x+y)%n));
	}
	printf("! %d ",top);
	For(i,1,top) q[i].write(),putchar(' ');
}