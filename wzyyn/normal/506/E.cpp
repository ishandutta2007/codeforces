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
const int mo=10007;
int n,m;
char s[205];
int f[205][205][105];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
struct Mat{
	int a[315][315];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat ans;
		For(i,1,310) For(j,i,310){
			ll tmp=0;
			For(k,i,j) tmp+=a[i][k]*b.a[k][j];
			ans.a[i][j]=tmp%mo;
		}
		return ans;
	}
}A,B;
Mat power(Mat a,int b){
	Mat s;
	For(i,1,310) s.a[i][i]=1;
	for (;b;b/=2,a=a*a)
		if (b&1) s=s*a;
	return s;
}
void init(int n){
	For(i,1,204) A.a[i][i]=24;
	For(i,206,310) A.a[i][i]=25;
	For(i,1,309) A.a[i][i+1]=1;
	A.a[205][205]=26; A=power(A,n);
	For(i,1,204) B.a[i][i]=24;
	For(i,205,310) B.a[i][i]=25;
	For(i,1,309) B.a[i][i+1]=1;
	B=power(B,n);
}
int calc(int s24,int s25,int s26){
	//cout<<s24<<' '<<s25<<' '<<s26<<endl;
	if (s26) return A.a[205-s24][205+s25];
	else return B.a[205-s24][204+s25];
}
int count(int odd){
	int ans=0;
	For(i,0,m+1) For(j,0,m+1)
		if (j==i-2||j==i-1||(j==i&&odd))
			For(k,0,m/2+1) if (f[i][j][k]){
				int s24=i-1+m-j-2*k,s25=k,s26=0;
				if (i!=j) ++s26; else ++s25;
				int tmp=calc(s24,s25,s26)*(odd&&j!=i?26:1);
				ans=(ans+1ll*f[i][j][k]*tmp)%mo;
				//cout<<i<<' '<<j<<' '<<k<<' '<<s24<<' '<<s25<<' '<<s26<<' '<<ans<<endl;
			}
	return ans;
}
int main(){
	scanf("%s",s+1);
	scanf("%d",&n);
	m=strlen(s+1); n+=m;
	f[1][m][0]=1;
	For(i,1,m) Rep(j,m,i)
		For(k,0,m/2+1)
			if (s[i]==s[j])
				UPD(f[i+1][j-1][k+1],f[i][j][k]);
			else{
				UPD(f[i+1][j][k],f[i][j][k]);
				UPD(f[i][j-1][k],f[i][j][k]);
			}
	init(n/2);
	printf("%d\n",count(n%2));
}