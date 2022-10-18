/*
 
| _ _|
 ` _x 
  /  |
 /  c ?
| |||
| (c_c_)_)

*/

#include<cstdio>
#include<algorithm>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define ll long long
#define N 100005

int n;
pii x[N],y[N];

bool fx[N],fy[N];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i].fir,&y[i].fir);
		x[i].sec=y[i].sec=i;
	}
	std::sort(x+1,x+n+1),std::sort(y+1,y+n+1);
	int mid=(n+1)>>1;
	for(int i=1;i<=n;i++)
		fx[x[i].sec]=fy[y[i].sec]=i<=mid;
	if((n&1)&&x[mid].sec!=y[mid].sec){
		for(int i=1;i<mid;i++)
			ans-=2ll*(x[i].fir+y[i].fir);
		for(int i=mid+1;i<=n;i++)
			ans+=2ll*(x[i].fir+y[i].fir);
	}
	else{
		if(n&1){
			for(int i=1;i<mid;i++)
				ans-=2ll*(x[i].fir+y[i].fir);
			for(int i=mid+1;i<=n;i++)
				ans+=2ll*(x[i].fir+y[i].fir);
			bool f1=0,f2=0;
			for(int i=1;i<=n;i++){
				if(i==x[mid].sec)
					continue;
				if(fx[i]==fy[i])
					f1=1;
				else
					f2=1;
			}
			if(f1&&f2)
				ans-=2ll*std::min(std::min(x[mid+1].fir-x[mid].fir,x[mid].fir-x[mid-1].fir),std::min(y[mid+1].fir-y[mid].fir,y[mid].fir-y[mid-1].fir));
		}
		else{
			for(int i=1;i<=mid;i++)
				ans-=2ll*(x[i].fir+y[i].fir);
			for(int i=mid+1;i<=n;i++)
				ans+=2ll*(x[i].fir+y[i].fir);
			bool f1=0,f2=0;
			for(int i=1;i<=n;i++){
				if(fx[i]==fy[i])
					f1=1;
				else
					f2=1;
			}
			if(f1&&f2)
				ans-=2ll*std::min(x[mid+1].fir-x[mid].fir,y[mid+1].fir-y[mid].fir);
		}
	}
	printf("%lld\n",ans);
}