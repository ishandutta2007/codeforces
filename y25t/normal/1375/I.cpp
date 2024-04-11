#include<bits/stdc++.h>
#define ll long long
#define lf long double
#define eps 1e-9
#define N 10005

struct HQ{
	lf s,x,y,z;
	HQ(lf s_=0,lf x_=0,lf y_=0,lf z_=0){
		s=s_,x=x_,y=y_,z=z_;
	}
	inline lf nm(){
		return s*s+x*x+y*y+z*z;
	}
	inline void wr(){
		printf("%lld %lld %lld\n",(ll)roundl(x),(ll)roundl(y),(ll)roundl(z));
	}
};
HQ operator - (HQ a,HQ b){
	return HQ(a.s-b.s,a.x-b.x,a.y-b.y,a.z-b.z);
}
HQ operator * (HQ a,lf b){
	return HQ(a.s*b,a.x*b,a.y*b,a.z*b);
}
HQ operator * (HQ a,HQ b){
	return HQ(a.s*b.s-a.x*b.x-a.y*b.y-a.z*b.z,a.s*b.x+a.x*b.s+a.y*b.z-a.z*b.y,
				a.s*b.y-a.x*b.z+a.y*b.s+a.z*b.x,a.s*b.z+a.x*b.y-a.y*b.x+a.z*b.s);
}
HQ operator ! (HQ a){
	return HQ(a.s,-a.x,-a.y,-a.z);
}
HQ operator ~ (HQ a){
	HQ u(roundl(a.s),roundl(a.x),roundl(a.y),roundl(a.z))
		,v(floorl(a.s)+.5,floorl(a.x)+.5,floorl(a.y)+.5,floorl(a.z)+.5);
	return (a-u).nm()<(a-v).nm()?u:v;
}
HQ operator / (HQ a,HQ b){
	return (!b)*a*(1.0/b.nm());
}
HQ operator % (HQ a,HQ b){
	return a-b*~(a/b);
}
inline HQ gcd(HQ a,HQ b){
	return b.nm()<eps?a:gcd(b,a%b);
}

int n;
HQ a[N];

HQ v;
ll G;
std::vector<int> d;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf%Lf",&a[i].x,&a[i].y,&a[i].z);
		v=gcd(v,a[i]),G=std::__gcd(G,(ll)a[i].nm());
	}
	for(int i=1;1ll*i*i<=G;i++)
		if(!(G%(1ll*i*i)))
			d.push_back(i);
	std::reverse(d.begin(),d.end());
	for(auto r:d){
		HQ u=gcd(v,HQ((lf)r));
		if(fabs(u.nm()-r)>eps)
			continue;
		bool flg=1;
		for(int i=1;i<=n;i++){
			HQ b=(!u)*a[i]*u*(1./((lf)r*r));
			if(fabs(b.s-roundl(b.s))>eps||fabs(b.x-roundl(b.x))>eps|| 
				fabs(b.y-roundl(b.y))>eps||fabs(b.z-roundl(b.z))>eps){
				flg=0;
				break;
			}
		}
		if(flg){
			printf("%lld\n",1ll*r*r);
			(u*HQ(0,1,0,0)*!u).wr(),(u*HQ(0,0,1,0)*!u).wr(),(u*HQ(0,0,0,1)*!u).wr();
			break;
		}
	}
}