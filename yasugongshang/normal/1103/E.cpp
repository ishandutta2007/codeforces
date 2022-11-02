#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define fi first
#define se second
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const ull mod=(ll)1<<58;
const int N=100000;
int zy[10][10];
struct data{
	ull a[5];
	ull& operator [](int x){
		return a[x];
	}
}f[10],A[N];
data operator *(data a,data b){
	data c; memset(&c,0,sizeof(c));
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			c[(i+j)%5]+=a[i]*b[j];
		}
	}
	return c;
}
data ksm(data a,int b){
	data ans; memset(&ans,0,sizeof(ans)); ans[0]=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a;
		a=a*a;
	}
	return ans;
}
data hb(data& a,data b,int k,int id){
	for(int i=0;i<5;i++)a[i]+=b[i+k>=5?i+k-5:i+k]*id;
	return a;
}
void bao(data *a,int zy[10][10]){
	static data b[10];
	memset(b,0,sizeof(b));
	//for(int i=0;i<10;i++)cout<<a[i][0]<<" "; puts("");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)if(zy[i][j]&1)hb(b[i],a[j],(zy[i][j]+5)/2%5,-1); else hb(b[i],a[j],zy[i][j]/2,1);
	}
	for(int i=0;i<10;i++)a[i]=b[i];
	//for(int i=0;i<10;i++)cout<<a[i][0]<<" "; puts(""); exit(0);
}
/*6 8 10 12 14*/
void DFT(data *a,int dq[10][10]){
	for(int i=1;i<N;i*=10){
		int d=i*10;
		for(int j=0;j<N;j+=d){
			for(int k=j;k<j+i;k++){
				for(int l=0,o=k;l<10;l++,o+=i)f[l]=a[o];
				bao(f,dq);
				for(int l=0,o=k;l<10;l++,o+=i)a[o]=f[l];
			}
		}
	}
}
int main(){
	int n=read();
	for(int i=0;i<n;i++)A[read()][0]++;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)zy[i][j]=i*j%10;
	/*for(int i=0;i<10;i++){
		for(int j=0;j<10;j++)cout<<zy[i][j]<<" "; puts("");
	}return 0;*/
	//for(int i=0;i<10;i++)cout<<A[i][0]<<" "; puts("");
	DFT(A,zy);
	//for(int i=0;i<10;i++)cout<<A[i][0]<<" "; puts("");
	for(int i=0;i<N;i++)A[i]=ksm(A[i],n);
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)zy[i][j]=(10-zy[i][j])%10;
	DFT(A,zy);
	//for(int i=0;i<10;i++)cout<<A[i][1]<<" "; puts(""); return 0;
	ull inv=(ull)14757395258967641293; 
	inv=inv*inv*inv*inv*inv;
	/*for(int i=0;i<30;i++){
		cout<<A[i][0]<<endl;
	}*/
	for(int i=0;i<n;i++){
		//for(int j=0;j<10;j++)cout<<A[i][j]<<" ";
		A[i][0]-=A[i][1];
		writeln((A[i][0]>>5)*inv%mod);
	}
}
/*
1 1 
1 -1
*/