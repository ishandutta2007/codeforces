#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=300005,INF=0x3f3f3f3f;

int n,c0,c1,min_r=INF,ans_id,ans_len,ans0[MAXN],ans1[MAXN];

struct data{
	int x,id;
	bool operator <(const data v)const{return x<v.x;}
	bool operator <(const int v)const{return x<v;}
} a[MAXN];

int main(){
	scanf("%d%d%d",&n,&c0,&c1);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		double now_=1.0*c0/i;
		int now=now_;
		if (now<now_) now++;
		int k=lower_bound(a+1,a+1+n,now)-a;
		if (k+i-1<=n&&k+i-1<=min_r) min_r=k+i-1,ans_id=k,ans_len=i;
	}
	for (int i=n;i>min_r;i--){
		if (c1<=1ll*a[i].x*(n-i+1)){
			printf("Yes\n");
			printf("%d %d\n",ans_len,n-i+1);
			for (int j=ans_id;j<=ans_id+ans_len-1;j++){
				if (j==ans_id) printf("%d",a[j].id);
				else printf(" %d",a[j].id);
			}
			printf("\n");
			for (int j=i;j<=n;j++){
				if (j==i) printf("%d",a[j].id);
				else printf(" %d",a[j].id);
			}
			printf("\n");
			return 0;
		}
	}
	std::swap(c0,c1);
	min_r=INF; ans_id=ans_len=0;
	for (int i=1;i<=n;i++){
		double now_=1.0*c0/i;
		int now=now_;
		if (now<now_) now++;
		int k=lower_bound(a+1,a+1+n,now)-a;
		if (k+i-1<=n&&k+i-1<=min_r) min_r=k+i-1,ans_id=k,ans_len=i;
	}
	for (int i=n;i>min_r;i--){
		if (c1<=1ll*a[i].x*(n-i+1)){
			printf("Yes\n");
			printf("%d %d\n",n-i+1,ans_len);
			for (int j=i;j<=n;j++){
				if (j==i) printf("%d",a[j].id);
				else printf(" %d",a[j].id);
			}
			printf("\n");
			for (int j=ans_id;j<=ans_id+ans_len-1;j++){
				if (j==ans_id) printf("%d",a[j].id);
				else printf(" %d",a[j].id);
			}
			printf("\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}