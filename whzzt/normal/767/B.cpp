#include"bits/stdc++.h"
using namespace std;
#define gc getchar()
template<class Tp>
void gi(Tp&x){
	x=0;int f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=gc;x*=f;
}

const int N=100005;
typedef long long ll;

int n;
ll T[N],ans,s,t,h,last,p,res;
#define A(x) ((x)>0?(x):-(x))
int main(){
	gi(s),gi(t),gi(h),gi(n);
	for(int i=1;i<=n;i++)gi(T[i]);
	last=s-h;p=T[1]-1;ans=s;
	res=A(s-T[1]+1);
	for(int i=1;i<=n;i++){
		if(T[i]<=ans)ans+=h;else break;
		if(ans+h>t)break;
		if(res>A(ans-T[i+1]))res=A(ans-T[i+1]),p=T[i+1]-1;
	}
	if(ans+h<=t) cout<<ans<<endl;
	else cout<<p<<endl;
	return 0;
}