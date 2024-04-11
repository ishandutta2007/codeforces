#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k;
char ch[300030];
int cr[300030];
int A[2][20010],B[2][20010],C[2][20010];
void set(int *b,int num){b[num/30]|=(1<<(num%30));}
int fnd(int *a,int *b,int sa,int sb){
	int p = 0;
	int al = sa/30,lmska = (1<<(sa%30))-1,rmska = (1<<30)-1-lmska,lna = sa%30,rna = 30-lna;
	int bl = sb/30,lmskb = (1<<(sb%30))-1,rmskb = (1<<30)-1-lmskb,lnb = sb%30,rnb = 30-lnb;
	//cout<<sa<<' '<<sb<<":";
	while(sa+p<n+100 && sb+p<n+100){
		
		int ca = (a[al]&rmska)>>lna | (a[al+1]&lmska)<<rna,cb = (b[bl]&rmskb)>>lnb | (b[bl+1]&lmskb)<<rnb;
		//cout<<ca<<' '<<cb<<endl;
		if((ca&cb) !=0){
			return 1+p+__builtin_ctz(ca&cb);
		}
		p+=30;
		al+=1;
		bl+=1;
	}
	return n+100;
}
int main() {
	cin>>ch;
	n = strlen(ch);
	for(int i=0;i<n;i++){
		set(A[ch[i]-'0'],i);
		if(i&1){
			set(B[ch[i]-'0'],i/2);
		}else{
			set(C[ch[i]-'0'],i/2);
		}
	}
	ll ans = 0;
	cr[n] = n;
	for(int i=0;i<n;i++){
		int cc;
		int ccol = ch[i]-'0';
		cr[i] = n;
		
		if(i&1){
			cc = fnd(A[ccol],B[ccol],i+1,(i/2)+1);
			if(i+cc*2<n) cr[i] = i+cc*2;
			else cc = 300030;
		}else{
			cc = fnd(A[ccol],C[ccol],i+1,(i/2)+1);
			if(i+cc*2<n) cr[i] = i+cc*2;
			else cc = 300030;
		}
		//cout<<i<<' '<<cr[i]<<endl;
		//if(i == 14)break;
	}
	for(int i=n-1;i>=0;i--){
		cr[i] = min(cr[i],cr[i+1]);
		ans = ans+n-cr[i];
	}
	
	cout<<ans<<endl;
	return 0;
}