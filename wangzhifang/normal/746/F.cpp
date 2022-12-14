#include <cstdio>
#include <set>
#include <algorithm>
#define max_n 200000
#define cs const
using namespace std;
typedef set<pair<int,int> >::iterator hp_iter;
int t[max_n+1],a[max_n+1];
template<typename T>void maxify(T&x,cs T&y){
	y>x&&(x=y);
}
int main(){
	int n,w,k;
	scanf("%d %d %d",&n,&w,&k);
	int nans=0,ans=0;
	set<pair<int,int> >hp1,hp2;
	for(int i=0; ++i<=n; scanf("%d",a+i));
	for(int i=0; ++i<=n; scanf("%d",t+i));
	for(int l=1,r=1,tmp,tmp2; r<=n; ++l){
		for(; r<=n; ++r)
			if(w)
				if(k<(tmp2=(t[r]+1)>>1))
					break;
				else
					k-=tmp2,maxify(ans,nans+=a[r]),hp1.insert(make_pair(t[r],r)),--w;
			else{
				if((tmp=hp1.begin()->first)<=t[r]&&k>=(tmp2=((t[r]+1)>>1)-((tmp+1)>>1)+tmp)){
					k-=tmp2,maxify(ans,nans+=a[r]);
					hp_iter p=hp1.begin();
					hp2.insert(*p);
					hp1.erase(p),hp1.insert(make_pair(t[r],r));
				}
				else
					if(tmp>t[r]&&k>=t[r])
						k-=t[r],ans=max(ans,nans+=a[r]),hp2.insert(make_pair(t[r],r));
					else
						break;
			}
		if(l>=r)
			++r;
		else{
			if(hp2.find(make_pair(t[l],l))!=hp2.end())
			    k+=t[l],nans-=a[l],hp2.erase(make_pair(t[l],l));
			else{
				k+=(t[l]+1)>>1,nans-=a[l],hp1.erase(make_pair(t[l],l)),++w;
				if(!hp2.empty()){
					hp_iter p=--hp2.end();
					k+=p->first-((p->first+1)>>1),hp1.insert(*p),--w;
					hp2.erase(p);
			    }
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}