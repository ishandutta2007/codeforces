#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int l,r,k;
};
bool  cmp(const node &x, const node &y)
{
    return x.l<y.l;
}
int main(){
	int t;	cin >> t;
	while(t--){
		int n;	cin >>n;
		struct node a[100005];
		for(int i=0; i<n; i++){
			cin >> a[i].l >> a[i].r;
			a[i].k = i;
		}
		int ans[100005];int t = 0;int k = 0;
		int flag1 = -1,flag2 = -1;
		sort(a,a+n,cmp);
		flag2 = a[0].r;
		ans[a[0].k] = 2;
		for(int i=1; i<n; i++){
			if(a[i].l>flag2){
				flag1 = max(flag1,a[i].r);
				k = 1;
				ans[a[i].k] = 1;
			}
			else if(a[i].l>flag1){
				flag2 = max(flag2,a[i].r);
				ans[a[i].k] = 2;
			}
		}
		if(!k){
			cout << -1 << endl;
			continue;
		}
		for(int i=0; i<n; i++){
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}