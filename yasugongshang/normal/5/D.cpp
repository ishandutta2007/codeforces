#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
#define ld long double
inline ll read(){
	ll x=0;char ch=gc();bool positive=1;
	for(;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	return positive?x:-x;
}
ld a,vm,L,d,lim;
ld get(ld a,ld L,ld v0,ld lim){
    ld vt=sqrt(2*a*L+v0*v0);
    if(vt<=lim)return (vt-v0)/a;
    else return (lim-v0)/a+(L-(lim*lim-v0*v0)/2/a)/lim;
}
int main(){
    a=read(); vm=read(); L=read(); d=read(); lim=read();
    if(d>L){
        lim=vm; d=L;
    }
    if(lim>vm)lim=vm;
    ld vt=sqrt(2*a*d);
    if(vt>lim){
        ld mv=sqrt((d*a*2+lim*lim)/2); //cout<<mv<<" "<<vm<<endl;
        if(mv<=vm){
            ld ttt=mv/a+(mv-lim)/a;
            double ans=ttt+get(a,L-d,lim,vm);
            printf("%.10lf\n",ans);    
        }else{
            ld ttt=vm/a+(vm-lim)/a+(d-vm*vm/2/a-(vm*vm-lim*lim)/2/a)/vm;
            double ans=ttt+get(a,L-d,lim,vm);
            printf("%.10lf\n",ans);
        }
        /*vt^2-v0^2=2as*/
    }else{
        double ans=get(a,L,0,vm);
        printf("%.10lf\n",ans);
    }
}
/*
t
x

x*x/a/2+(x^2-lim^2)/a/2=L

x*x+x*x-lim^2=L*a*2
*/