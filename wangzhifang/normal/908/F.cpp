#include <cstdio>
#include <algorithm>
#define max_n 300000
using namespace std;
#if __cplusplus<201103L
const class nullptr_t{
	public:
	    template<class T>
	    inline operator T*() const
	        { return 0; }
	
	    template<class C, class T>
	    inline operator T C::*() const
	        { return 0; }
	private:
	    void operator&()const;
}nullptr={};
#endif
#define cs const
#define tpl template
#define tpn typename
tpl<tpn T1,tpn T2>void maxify(T1&x,cs T2&y){
	y>x&&(x=y);
}
#undef cs
#undef tpl
#undef tpn
typedef pair<int,int> pii;
typedef long long ll;
pii mass[max_n];
int main(){
	int n;
	scanf("%d",&n);
	char ch;
	for(pii*i=mass,*ed=mass+n; i<ed; ++i){
		scanf("%d %c",&i->first,&ch);
		i->second=(ch=='R'?0:(ch=='B'?1:2));
	}
	ll ans = 0;
	for(pii*i=mass,*ed=mass+n-1; i<ed; ++i)
		i->second==2&&(i+1)->second==2&&(ans+=(i+1)->first-i->first);
	for(pii*i=mass,*ed=mass+n,*j=mass; i<ed; i=j){
		if(i->second==2){
			j=i+1;
			continue;
		}
		pii*imin1=nullptr,*imin2=nullptr,*imax1=nullptr,*imax2=nullptr;
		int lst1=(i-1)->first,lst2=lst1,max1=0,max2=0;
		for(; j<ed&&j->second!=2; ++j){
			if(j->second==0){
				if(!imin1)
					imin1=imax1=j;
				else
					imax1=j;
				maxify(max1,j->first-lst1);
				lst1=j->first;
			}
			else{
				if(!imin2)
					imin2=imax2=j;
				else
					imax2=j;
				maxify(max2,j->first-lst2);
				lst2=j->first;
			}
		}
		if(i==mass)
			if(j==ed){
				if(imin1)
					ans+=imax1->first-imin1->first;
				if(imin2)
					ans+=imax2->first-imin2->first;
				break;
			}
			else{
				if(imin1)
					ans+=j->first-imin1->first;
				if(imin2)
					ans+=j->first-imin2->first;
			}
		else
			if(j==ed){
				if(imin1)
					ans+=imax1->first-(i-1)->first;
				if(imin2)
					ans+=imax2->first-(i-1)->first;
			}
			else{
				int len=j->first-(i-1)->first;
				maxify(max1,j->first-lst1);
				maxify(max2,j->first-lst2);
				ans+=min(len*3-max1-max2,len<<1);
			}
	}
	printf("%lld\n",ans);
	return 0;
}