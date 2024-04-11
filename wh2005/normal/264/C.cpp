#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9;
const ll inf = 1e18;
int n,m;ll f[N],c[N],v[N],p[N];
ll read(){
    ll res=0,sign=1;
    char c;
    while ((c=getchar())<'0'||c>'9') if (c=='-') sign=-1;
    res=(c^48);
    while ((c=getchar())>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48);
    return res*sign;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=n;i++) c[i]=read();
	while(m--){
		ll a=read(),b=read();
		for(int i=0;i<=n;i++) f[i]=-inf,p[i]=-inf;
        int fi=0,se=0;p[0]=0;
		for(int i=1;i<=n;i++){
            int k=(fi==c[i])?se:fi;
            if(p[c[i]]>-inf) f[i]=max(f[i],max(p[c[i]]+a*v[i],p[k]+b*v[i]));
            else f[i]=max(f[i],p[k]+b*v[i]);
            p[c[i]]=max(f[i],p[c[i]]);
            if(fi==c[i]) continue;
            if(p[c[i]]>p[fi]) se=fi,fi=c[i];
            else if(p[c[i]]>p[se]) se=c[i];
        }
		printf("%lld\n",p[fi]);
	}
	return 0;
}